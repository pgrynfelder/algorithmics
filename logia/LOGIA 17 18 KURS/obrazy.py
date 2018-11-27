from turtle import *

class Bitmap(list):
    def __init__(self, bmp):
        super().__init__([list(row) for row in bmp])
        self.width = max([len(row) for row in self])
        self.height = len(self)
    def draw(self,
             pixel_width,
             full_color = "#000000",
             pen_color = "#000000",
             empty_color = "#ffffff",
             pen_empty_color = "#ffffff"):
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
                if pixel: fillcolor(empty_color); pencolor(pen_empty_color)
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
    def from_list(bits, w, h):
        new = Bitmap([[0]*w]*h)
        for i in range(len(bits)):
            new.subsequent_pixel(i, bits[i])
        return new
    def __repr__(self):
        return "Bitmap([" + "\n        ".join([str(row) for row in self]) + "])"

def convert(n, base):
    new = []
    while n:
        new = [int(n % base)] + new
        n //= base
    return new
            
def addzeroes(x, desired_number):
    while len(x) < desired_number:
        x = [0] + x
    return x

def obrazy(codes):
    codes = [addzeroes(convert(x, 2), 25) for x in codes]

    pu()
    for x in range(10):
        setpos(-210, 100-x*20)
        for y in codes[x*10:(x+1)*10]:
            Bitmap.from_list(y, 5, 5).draw(4)
            fd(20)
    colors = []
    for x in codes:
        colors.append('#'+"".join([hex(int("".join([str(z) for z in x[y*8:(y+1)*8]]), base=2)).lstrip('0x').rjust(2,"0") for y in range(0,3)]))
    for x in range(10):
        setpos(10, 100-x*20)
        for y in colors[x*10:(x+1)*10]:
            Bitmap([[1]]).draw(20, y, y)
            fd(20)
