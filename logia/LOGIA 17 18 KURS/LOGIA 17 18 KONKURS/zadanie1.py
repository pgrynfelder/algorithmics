from turtle import *

class Bitmap():
    def __init__(self, bmp):
        self.bmp = bmp
        self.width = max([len(row) for row in self.bmp])
        self.height = len(self.bmp)
    def draw(self, pixel_width, color):
        was_pen_down = pen()["pendown"]
        penup()
        bmp_start = pos()
        fillcolor(color)
        pencolor(color)
        for row in self.bmp:
            row_start = pos()
            for pixel in row:
                if pixel: pendown(); begin_fill()
                for _ in range(4): fd(pixel_width); rt(90)
                if pixel: penup(); end_fill()
                fd(pixel_width)
            setpos(row_start)
            rt(90)
            fd(pixel_width)
            lt(90)
        setpos(bmp_start)
        if was_pen_down: pendown()


def rama():
    penup()
    setpos(-490/2, 490/2)
    bmp1 = Bitmap(((1,1,1,1,1,1,1,1,1,0),
                   (1,0,0,0,0,0,0,0,1,0),
                   (1,0,1,1,1,1,1,0,1,0),
                   (1,0,1,0,0,0,1,0,1,0),
                   (1,0,1,0,1,0,1,0,1,0),
                   (1,0,1,0,0,0,1,0,1,0),
                   (1,0,1,1,1,1,1,0,1,1),
                   (1,0,0,0,0,0,0,0,0,0),
                   (1,1,1,1,1,1,1,0,1,1)))
    bmp2 = Bitmap(((1,1,1,1,1,1,1,1,1,0),
                   (1,0,0,0,0,0,0,0,1,0),
                   (1,0,1,1,1,1,1,0,1,0),
                   (1,0,1,0,0,0,1,0,1,0),
                   (1,1,1,1,1,0,1,0,1,0),
                   (0,0,1,0,1,0,1,0,1,0),
                   (1,1,1,0,1,0,1,0,1,1),
                   (0,0,0,0,1,0,1,0,0,0),
                   (1,1,1,1,1,0,1,1,1,1)))
    n = 490 / (bmp1.width + 3*bmp2.width + bmp1.height)
    for x in range(4):
        bmp1.draw(n, "brown")
        fd(bmp1.width * n)
        for y in range(3):
            bmp2.draw(n, "brown")
            fd(bmp2.width * n)
        fd(bmp1.height * n)
        rt(90)
