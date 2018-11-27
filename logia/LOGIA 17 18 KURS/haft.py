from turtle import *

def convert(decimal, target_base):
    result = []
    while decimal:
        decimal, digit = divmod(decimal, target_base)
        result.append(digit)
    result.reverse()
    return result
        
def cross(n, colorcode):
    #pensize(8)
    pu()
    startpos = pos()
    colors = {0:"#bbbbbb", 1:"red", 2:"black"}
    pencolor(colors[colorcode])
    rt(45)
    pd()
    fd(n * 2 ** (1/2))
    pu()
    setpos(startpos[0], startpos[1] - n)
    pd()
    lt(90)
    fd(n * 2 ** (1/2))
    pu()
    rt(45)
    setpos(startpos)
    
def fill(obj, length, to_be_filled):
    to_be_filled.reverse()
    for _ in range(length - len(to_be_filled)):
        to_be_filled.append(obj)
    to_be_filled.reverse()
    return to_be_filled

def haft(encoded):
    pu()
    fd(-200)
    lt(90)
    fd(200)
    rt(90)
    n = 400 / len(encoded)
    decoded = [fill(0, len(encoded), convert(x,3)) for x in encoded]
    for row in decoded:
        startpos = pos()
        print(row)
        for cell in row:
            cross(n, cell)
            fd(n)
        goto((startpos[0], startpos[1] - n))
