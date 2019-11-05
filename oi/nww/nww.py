from math import gcd, floor, sqrt

l = 1; r = 6*int(1e6)
lcm = dict()
for i in range(l, r+1):
    current_lcm = i*(i+1)
    for j in range(i+2, r+1):
        current_lcm = (current_lcm * j) // gcd(current_lcm, j)
        if current_lcm > 1e18: break
        
        if lcm.get(current_lcm, (1e19, 1e19)) > (i, j):
            lcm[current_lcm] = (i, j)

""" 
For sequence a, a + 1, ..., b

lcm is a multiple of 
b! / (a-1)! / (b-a)! 

so lcm >= b! / (a-1)! / (b-a)! 
"""