import zadanie1
import zadanie2
import zadanie3
from turtle import *

def rectangle():
    setpos(-794/2,497/2)
    for _ in range(2): fd(794); rt(90); fd(497); rt(90)
    setpos(0,0)
                                           
TOCHECK = 3

tracer(0)
if TOCHECK == 1:
    zadanie1.rama()
elif TOCHECK == 2:
    rectangle(); zadanie2.flaga(14)
elif TOCHECK == 3:
    tests = [1, 29, 64, 1000000]
    for x in tests:
        print(zadanie3.ile(x))
tracer(1)
