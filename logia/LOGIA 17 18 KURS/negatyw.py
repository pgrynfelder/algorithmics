import random
from turtle import *

class Bitmap(list):
    def __init__(self, bmp):
        super().__init__([list(row) for row in bmp])
        self.width = max([len(row) for row in self])
        self.height = len(self)
    def draw(self,
             pixel_width,
             pen_color = "BLACK",
             pen_empty_color = "BLACK",
             full_color = "#444444",
             empty_color = "#bbbbbb"):
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

    def subsequent_pixel(self, i, *value):
        if value: self[i // self.width][i % self.width] = int(value[0])
        return self[i // self.width][i % self.width]
    def negative(self):
        return Bitmap([[(p + 1) % 2 for p in row] for row in self])
    def __repr__(self):
        return "Bitmap([" + "\n        ".join([str(row) for row in self]) + "])"

def negatyw(pixels):
    n = pixels[0]
    pixels = pixels[1:]
    b = Bitmap([[0] * n] * n)
    for p in pixels:
        b.subsequent_pixel(p, 1)
        
    pu(); setpos(-630/2, 300/2)
    b.draw(300/b.width)
    fd(330)
    b.negative().draw(300/b.width)
