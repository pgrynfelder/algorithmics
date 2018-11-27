import os
import traceback

import pygame
pygame.init()

import states
from colors import Color

FILENAME = "res/map_europe.png"
STATE = states.ViewState
#STATE = states.CalibrateState
#STATE = states.FindState

MFIX = 256


display_info = pygame.display.Info()
mwidth, mheight = display_info.current_w, display_info.current_h
print("Display size is", (mwidth, mheight))
print("Create screen")
screen = pygame.display.set_mode((100, 100), pygame.RESIZABLE)
print("Load map image")
base_image = pygame.image.load(FILENAME).convert()
print("Get optimal screen size")
isize = base_image.get_size()
iwidth, iheight = isize
def find_display_size():
    if iwidth > iheight:
        width = mwidth - MFIX
        height = int(iheight / iwidth * width)
        print("p1", width, height)
        if height < mheight:
            return width, height
    height = mheight - MFIX
    width = int(iwidth / iheight * height)
    print("p2", width, height)
    if width < mwidth:
        return width, height
    print("p3", 640, int(iheight / iwidth * 640))
    return 640, int(iheight / iwidth * 640)
width, height = find_display_size()
image = pygame.transform.scale(base_image, (width, height))
print("Set screen size to", (width, height))
screen = pygame.display.set_mode((width, height), pygame.RESIZABLE)

FPS = 60

class App:
    def __init__(self):
        self.screen = screen
        self.map_image = image
        self.base_map_image = base_image
        self.image_size, self.base_image_size = (width, height), (iwidth, iheight)
        self.state = STATE(self)

    def run(self):
        clock = pygame.time.Clock()
        running = True
        while running:
            events = pygame.event.get()
            for event in events:
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.VIDEORESIZE:
                    self.map_image = pygame.transform.scale(base_image, event.size)
                    prev_size = self.image_size
                    self.image_size = event.size
                    try:
                        for point in self.state.points:
                            x = int(event.w / prev_size[0] * point.pos[0])
                            y = int(event.h / prev_size[1] * point.pos[1])
                            point.pos = (x, y)
                    except AttributeError:
                        pass
                    pygame.display.set_mode(event.size, pygame.RESIZABLE)
            pressed_keys = pygame.key.get_pressed()
            mouse_pos = pygame.mouse.get_pos()
            pressed_mouse = pygame.mouse.get_pressed()
            self.state.handle_events(events, pressed_keys, mouse_pos, pressed_mouse)
            self.state.update()
            screen.fill(Color.White)
            self.state.draw(self.screen)
            pygame.display.flip()
            clock.tick(60)

if __name__ == "__main__":
    app = App()
    try:
        app.run()
    except:
        traceback.print_exc()
        os.system("pause")
