def convert(n, base):
    new = ""
    while n:
        new = str(n % base) + new
        n //= base
    return new
def divsum(n):
    
    result = 0
    for x in range(1, int(n**(1/2))+1):
        if n % x == 0:
            result += x
            if n // x != x:
                result += n // x
    return result

def first():
    yield 2
    yield 3
    i = 0
    while True:
        i+=1
        if divsum(6*i - 1) == 6*i:
            yield 6*i-1
        if divsum(6*i + 1) == 6*i+2:
            yield 6*i+1

def rozklad(number):
    n = number
    result = []
    for x in first():
        while n % x == 0:
            n //= x
            result.append(x)
        if n < 2 or x > n**(1/2):
            break
    if n > 1:
        result += n
    return result
