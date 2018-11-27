from turtle import *
import math

def elem(n, color):
    startpos = pos()
    fd(n); rt(90); fd(n); lt(90)
    pendown()
    pencolor("black")
    fillcolor(color)
    begin_fill()
    fd(n); rt(90)
    fd(2*n); lt(90)
    fd(2*n); lt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(2*n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(4*n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    end_fill()
    penup()
    setpos(startpos)

def yellow(n):
    elem(n, "yellow")

def green(n):
    startpos = pos()
    lt(180)
    bk(6*n)
    rt(90)
    bk(4*n)
    lt(90)
    elem(n, "green")
    lt(180)
    setpos(startpos)

def flaga(number):
    penup()
    n = 8
    xoffset = ((number-1) * n * 5.5 + n * 6)/2
    yoffset = (math.floor(number/2) * n * 2 + number * 3 * n)/2
    bk(xoffset)
    lt(90)
    fd(yoffset)
    rt(90)
    
    for x in range(number, 0, -1):
        startcol = pos()
        for y in range(x):
            if (x+y) % 2 == 1:
                green(n)
                rt(90)
                fd(3*n)
                lt(90)
            else:
                yellow(n)
                rt(90)
                fd(5*n)
                lt(90)
        setpos(startcol)
        fd(5.5*n)
        rt(90)
        if x % 2 == 1:
            fd(0.5*n)
        else:
            fd(2.5*n)
        lt(90)
