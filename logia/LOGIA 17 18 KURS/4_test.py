import math

def colatz(c, n):
    for i in range(n-1):
        if c % 2 == 0:
            c //= 2
        else:
            c = 3*c + 1
    return c

def divsum(n):
    
    result = 0
    for x in range(1, int(n**(1/2))+1):
        if n % x == 0:
            result += x
            if n // x != x:
                result += n // x
    return result

def divs(n):
    result = []
    for x in range(1, int(n**(1/2))+1):
        if n % x == 0:
            result.append(x)
            if n // x != x:
                result.append(n // x)
    return result

def czy_pierwsza(n):
    return divsum(n) == n + 1

def suma_dziel(n):
    return divsum(n)

def test(x):
    return x%3==0 and x//10 == 3 and str(x)!=str(x)[::-1] and '0' not in str(x)

def convert(n, base):
    new = []
    while n:
        new = [n % base] + new
        n //= base
    return new

def lol(word, n):
    keydict = dict(zip("aeojkt", "012345"))
    number = "".join([keydict[x] for x in word])
    return int(number, n)
    
def cezar(word, key):
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    key %= len(alpha)
    word = "".join([alpha[(alpha.index(x) + key) % len(alpha)] for x in word])
    return word

def scm(a,b):
    return a * b // math.gcd(a,b)

def fibo(s,e):
    result = []
    a = 0
    b = 1
    for i in range(e):
        a, b = b%10, a + b
        if i > s - 2:
            result.append(a)
    return result

def test2(word):
    vowels = "eyuioa"
    points = 2
    for x in vowels:
        if x in word:
            points -= 1
            break
    if len(word) % 2 == 0:
        points -= 1
    return points == 0
