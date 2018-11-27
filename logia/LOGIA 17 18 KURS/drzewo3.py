from turtle import * 
def tree(h, n):
    if n > 1:
        fd(h)
        lt(60)
        for _ in range(3): tree(h/2, n-1); rt(60)
        lt(120)
        fd(-h)
    else:
        fd(h)
        fd(-h)
        
def drzewo3(h, n):
    totalheight = h + h * ( (2**(n-1)-1) / (2**(n-1)) )
    lt(90)
    pu()
    fd(-totalheight / 2)
    pd()
    tree(h, n)
