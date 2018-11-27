from turtle import *
import random

class Ships(list):
    def __init__(self, bmp):
        super().__init__([list(row) for row in bmp])
        self.width = max([len(row) for row in self])
        self.height = len(self)
    def draw(self,
             pixel_width,
             pen_color = "BLACK",
             pen_empty_color = "BLACK",
             full_color = "GREEN",
             empty_color = "WHITE"):
        was_pen_down = pen()["pendown"]
        penup()
        bmp_start = pos()
        fillcolor(empty_color)
        pencolor(pen_empty_color)
        for row in self:
            row_start = pos()
            for pixel in row:
                if pixel: fillcolor(full_color); pencolor(pen_color)
                pendown(); begin_fill()
                for _ in range(4): fd(pixel_width); rt(90)
                end_fill(); penup()
                if pixel: fillcolor(empty_color); pencolor(pen_color)
                fd(pixel_width)
            setpos(row_start)
            rt(90)
            fd(pixel_width)
            lt(90)
        setpos(bmp_start)
        if was_pen_down: pendown()
    def addShip(self, sp, ep):        
        bsp = (sp[0]-1, sp[1]-1)
        bep = (ep[0]+1, ep[1]+1)
        #print(sp,ep)
        #print(bsp, bep)

        new = self.copy()
        for rowindex in range(sp[1], ep[1]+1):
            for cellindex in range(sp[0],ep[0]+1):
                if new[rowindex][cellindex]:
                    return False
        for rowindex in range(bsp[1], bep[1]+1):
            for cellindex in range(bsp[0], bep[0]+1):
                if rowindex != bsp[1] and rowindex != bep[1] and cellindex != bsp[0] and cellindex != bep[0]:
                    new[rowindex][cellindex] = 2
                else:
                    new[rowindex][cellindex] = 1
        
        self = new
        return True

    def __repr__(self):
        return "Bitmap([" + "\n        ".join([str(row) for row in self]) + "])"

def statki():
    toplace = [4, 3, 3, 2, 2, 2, 1, 1, 1, 1]
    b = Ships([[0] * 12] * 12)
    tries = 0
    for ship in toplace:
        while True:
            if random.randint(0,1): #horizontal
                sp = (random.randint(1, b.width - ship - 1), random.randint(1, b.height - 2))
                ep = (sp[0] + ship - 1, sp[1])
                if b.addShip(sp, ep):
                    break
            else: #vertical
                sp = (random.randint(1, b.width - 2), random.randint(1, b.height - ship - 1))
                ep = (sp[0], sp[1] + ship- 1)
                if b.addShip(sp, ep):
                    break
    b = Ships([[1 if cell == 2 else 0 for cell in row[1:-1]] for row in b[1:-1]])

    penup()
    setpos(-200, 200)
    b.draw(40)
    setpos(0,0)
