import numpy as np

(n,m,k) = [int(x) for x in input().split()]
input()
a = set()
for x in range(n*m-1):
    (x, y, z, t) = [int(h) for h in input().split()]
    if (((x,y,z,t) in a) or ((z,t,x,y) in a)):
        print(x, y, z, t)
        break
    a.add((x,y,z,t))
