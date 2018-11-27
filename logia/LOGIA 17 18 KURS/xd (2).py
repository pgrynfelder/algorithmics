from turtle import *
speed(0)
#for i in range(2): fd(20); lt(90); fd(20); lt(180)
#for i in range(2): bk(20); rt(90); fd(20); lt(90)
#for i in range(2): bk(20); lt(180); bk(20); lt(90)
#for i in range(2): fd(20); rt(90); fd(20); lt(90)
#for i in range(2): fd(20); rt(90); fd(20); rt(90)

def motyw():
    for i in range(5):
        for j in range(4):
            fd(40); rt(90)
            fd(20); lt(90)
        lt(90)

#motyw()

def kwadrat(bok):
    for i in range(4):
        fd(bok); lt(90)

def piramida(n):
    bok=40
    for i in range(n):
        for k in range(i+1):
            kwadrat(bok)
            fd(bok)
        pu(); bk((i+1)*bok + bok/2)
        lt(90); bk(bok); rt(90); pd()

#piramida(3)

def prosto(bok1, bok2):
    for i in range(2):
        fd(bok1); lt(90)
        fd(bok2); lt(90)

#prosto(100,60)

def rozetka(a,n):
    rt(15)
    for i in range(n):
        for k in range(2):
            fd(a); lt(30); fd(a); lt(150)
        rt(30)

#rozetka(20, 7)
