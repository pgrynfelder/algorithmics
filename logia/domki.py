from turtle import *

def triangle1(a, colored):
    start = pos()
    fillcolor("#000000")
    if colored: begin_fill()
    fd(a); rt(90); fd(a); goto(start); lt(90)
    if colored: end_fill()

def triangle2(a, colored):
    start = pos()
    fillcolor("#000000")
    if colored: begin_fill()
    rt(90); fd(a); lt(90); fd(a); goto(start);
    if colored: end_fill()


def house(a, tocolor):
    start = pos()
    pd()
    lt(90)
    for x in range(1,9,2):
        triangle1(a, tocolor==x)
        triangle2(a, tocolor==x+1)
        rt(90)
    fd(a)
    lt(90)
    fd(a)
    rt(90)
    triangle2(a, tocolor % 2 == 0)
    rt(90)
    fd(2*a)
    rt(180)
    triangle1(a, tocolor == 9)
    rt(180)
    pu()
    goto(start)

def domki(n):
    a = 20
    for x in str(n):
        house(a, int(x))
        fd(2*a)




clearscreen()
tracer(0)
domki(2486)
fd(1)
domki(2)
tracer(1)
