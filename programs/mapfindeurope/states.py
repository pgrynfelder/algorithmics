import math
import random
import json

import pygame

from colors import Color

TOPLEFT = (0, 0)
# Set to None for user input
DEFAULT_FILENAME = "data.json"

class BaseState:
    def __init__(self, parent):
        self.parent = parent

    def handle_events(self, events, pressed_keys, mouse_pos, pressed_mouse):
        pass

    def update(self):
        pass

    def draw(self, screen):
        pass


class CalibrateState(BaseState):
    charset = set(chr(i) for i in range(ord("a"), ord("z")+1)) | set("ąęółżźćśń. ")
    def __init__(self, parent):
        super().__init__(parent)
        if DEFAULT_FILENAME is None:
            self.filename = input("Input new data filename (without extension): ") + ".json"
        else:
            self.filename = DEFAULT_FILENAME
        try:
            file = open(self.filename, "r", encoding="utf-8")
            self.data = json.load(file)
        except FileNotFoundError:
            self.data = {}
        self.file = None
        self.clicked, self.click_pos = False, None
        self.inputing, self.input_text, self.input_done = False, None, False
        self.input_click_pos = None
        self.font = pygame.font.Font("res/OpenSansCondensed-Light.ttf", 16)

    def handle_events(self, events, pressed_keys, mouse_pos, pressed_mouse):
        self.clicked, self.click_pos = False, None
        for event in events:
            if event.type == pygame.MOUSEBUTTONDOWN:
                self.clicked = True
                self.click_pos = event.pos
            if event.type == pygame.KEYDOWN:
                if self.inputing:
                    if event.unicode.lower() in self.charset:
                        self.input_text += event.unicode
                    elif event.key == pygame.K_RETURN:
                        self.input_done = True
                        self.new_name = self.input_text
                    elif self.input_text and event.key == pygame.K_BACKSPACE:
                        self.input_text = self.input_text[:-1]

    def update(self):
        if not self.inputing and self.clicked:
            self.new_w = round(self.click_pos[0] / self.parent.image_size[0], 5)
            self.new_h = round(self.click_pos[1] / self.parent.image_size[1], 5)
            self.inputing = True
            self.input_text = ""
            self.input_click_pos = self.click_pos
        if self.input_done:
            self.inputing = self.input_done = False
            self.input_text = self.input_click_pos = None
            if self.new_name:
                self.data[self.new_name] = (self.new_w, self.new_h)
                self.save_data()


    def draw(self, screen):
        screen.blit(self.parent.map_image, TOPLEFT)
        for name, rawpoint in self.data.items():
            pos = int(rawpoint[0] * self.parent.image_size[0]), int(rawpoint[1] * self.parent.image_size[1])
            point = MapPoint(pos, name)
            point.draw(screen)
        if self.inputing:
            point = MapPoint(self.input_click_pos, self.input_text, Color.Blue)
            point.draw(screen)


    def save_data(self):
        try:
            self.file = open(self.filename, "w", encoding="utf-8")
            self.file.seek(0); self.file.truncate()
            string = json.dumps(self.data, sort_keys=True, indent=4)
            self.file.write(string)
            self.file = None
        except Exception as e:
            print("Error while saving calibration data: ({}: {})".format(type(e).__name__, str(e)))
            print("Data:", self.data)


class ViewState(BaseState):
    def __init__(self, parent):
        super().__init__(parent)
        if DEFAULT_FILENAME is None:
            self.filename = input("Input filename to load (without extension): ") + ".json"
        else:
            self.filename = DEFAULT_FILENAME
        self.data = json.load(open(self.filename, "r", encoding="utf-8"))
        self.positions = [
            (int(rawpoint[0] * self.parent.image_size[0]), int(rawpoint[1] * self.parent.image_size[1]))
            for _, rawpoint in sorted(self.data.items())
        ]
        self.points = [
            MapPoint(pos, name)
            for pos, name  in zip(self.positions, sorted(self.data.keys()))
        ]
        self.current_filter = None

    def handle_events(self, events, pressed_keys, mouse_pos, pressed_mouse):
        for event in events:
            if event.type == pygame.KEYDOWN:
                if event.key in range(pygame.K_F1, pygame.K_F12 + 1):
                    v = event.key - pygame.K_F1
                    if v < len(filters):
                        self.current_filter = filters[v]
                    else:
                        self.current_filter = None

    def draw(self, screen):
        screen.blit(self.parent.map_image, TOPLEFT)
        for point in self.points:
            if self.current_filter is None or self.current_filter.applies(point):
                point.draw(screen)


class FindState(BaseState):
    font = pygame.font.Font("res/OpenSansCondensed-Light.ttf", 20)
    count = float("inf") # inf for all
    find_filter = None # none for all, set after filter definition
    def __init__(self, parent):
        super().__init__(parent)
        if DEFAULT_FILENAME is None:
            self.filename = input("Input filename to load (without extension): ") + ".json"
        else:
            self.filename = DEFAULT_FILENAME
        self.data = json.load(open(self.filename, "r", encoding="utf-8"))
        self.positions = [
            (int(rawpoint[0] * self.parent.image_size[0]), int(rawpoint[1] * self.parent.image_size[1]))
            for _, rawpoint in sorted(self.data.items())
        ]
        self.points = [
            MapPoint(pos, name)
            for pos, name  in zip(self.positions, sorted(self.data.keys()))
        ]
        self.all_find_points = self.points.copy()
        if self.find_filter is not None:
            self.all_find_points = [p for p in self.all_find_points if self.find_filter.applies(p)]
        random.shuffle(self.all_find_points)
        while len(self.all_find_points) > self.count:
            self.all_find_points.pop()
        self.current_to_find = None
        self.find_points = self.all_find_points.copy()
        self.found_points = []
        self.guesses = []
        self.guess_circles = []
        self.show_full_map = False

    def handle_events(self, events, pressed_keys, mouse_pos, pressed_mouse):
        self.clicked, self.click_pos = False, None
        for event in events:
            if event.type == pygame.MOUSEBUTTONDOWN:
                self.clicked = True
                self.click_pos = event.pos
        self.show_full_map = pressed_keys[pygame.K_F1]

    def update(self):
        if self.clicked and self.current_to_find is not None:
            self.found_points.append(self.current_to_find)
            self.guesses.append(self.click_pos)
            pos = self.current_to_find.pos
            radius = self.dist(pos, self.click_pos)
            if radius and radius < 500:
                self.guess_circles.append((pos, int(radius)))
            self.current_to_find = None
        if self.current_to_find is None and self.find_points:
            self.current_to_find = self.find_points.pop()

    def draw(self, screen):
        screen.blit(self.parent.map_image, TOPLEFT)
        if self.show_full_map:
            for point in self.points:
                point.draw(screen)
        else:
            for point in self.found_points:
                point.draw(screen)
            for pos, radius in self.guess_circles:
                pygame.draw.circle(screen, Color.Black, pos, radius, 1)
        if self.current_to_find is not None:
            render = self.font.render("Find {}! ({}/{})".format(self.current_to_find.name, 
                                                                len(self.guesses), 
                                                                len(self.all_find_points)),
                                      True, Color.Red, None)
            screen.blit(render, (4, 0))
        elif not self.find_points:
            render = self.font.render("Done!", True, Color.Red, None)
            screen.blit(render, (4, 0))

    def dist(self, p1, p2):
        return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

# - = - = -

class MapPoint:
    font = pygame.font.Font("res/OpenSansCondensed-Bold.ttf", 16)
    radius = 5
    def __init__(self, pos, name, color=None):
        self.pos = pos
        self.x, self.y = pos
        self._name, self._annotation = name, None
        if color is None:
            for f in filters:
                if f.applies(self):
                    self.color = f.fcolor
                    break
        else:
            self.color = color
        self.name = name        

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, name):
        self._name = name
        self.annotation = self.font.render(name, True, self.color, None)

    @property
    def anpoint(self):
        p = (self.pos[0] - self.annotation.get_width() / 2, self.pos[1] - self.annotation.get_height() - 4)
        if p[1] < 0:
            return (p[0], p[1] + self.annotation.get_height() + 8)
        else:
            return p

    def draw(self, screen):
        pygame.draw.circle(screen, self.color, self.pos, self.radius)
        screen.blit(self.annotation, self.anpoint)

class MapFilter:
    def __init__(self, name, value, unique=(), fcolor=Color.Black):
        self.name = name
        if isinstance(value, (list, tuple)):
            self.values = value
        else:
            self.values = (value,)
        self.unique = unique
        self.fcolor = fcolor

    def applies(self, map_point):
        return map_point.name in self.unique or any(map_point.name.startswith(v) for v in self.values)

class MapFilterOther:
    name = "Other"
    values = None
    fcolor = Color.dGray
    def applies(self, map_point):
        return not any(f.applies(map_point) for f in filters if f is not self)

filters = [
    MapFilter("Terrain Type", ("G.", "W.", "N."), fcolor=Color.Brown), # Góra, Wyżyna, Nizina
    MapFilter("Water", ("R.", "J.", "M.", "Z."), fcolor=Color.lBlue), # Rzeka, Jezioro, Morze, Zatoka
    MapFilter("Terrain Features", 
              ("P.", "K.", "C.", "Prz."), # Półwysep, Kanał, Cieśnina, Przylądek, 
              ("Mont Blanc", "Gerlach", "Etna", "Wezuwiusz"), # Szczyt, Wulkan
              fcolor=Color.Orange
    ),
    MapFilter("Islands", ("Ws.", "Wy."), fcolor=Color.Purple),
    MapFilterOther()
]