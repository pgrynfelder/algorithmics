from turtle import *
def puzzle(n):
    pd()
    lt(90)
    fd(n/2); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(2*n); rt(90)
    fd(n); rt(90)
    fd(n); lt(90)
    fd(n); lt(90)
    fd(n); rt(90)
    fd(n); rt(90)
    fd(2*n); lt(90)
    fd(n); rt(90)
    fd(n/2); rt(90)
    pu()
    
def rzad(n):
    pu()
    nwidth = 400 / (4 + (n-1) * 3)
    bk(200)
    for i in range(n):
        puzzle(nwidth)
        fd(nwidth * 3)


speed(0)
rzad(4)
setpos(0,0)
rzad(3)
setpos(0,0)
rzad(7)
setpos(0,0)
