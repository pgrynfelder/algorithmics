import math

def factors(n):
    for i in range(1, int(math.sqrt(n))+1):
        if n % i == 0:
            yield [i, n//i]

def liczby(numbers):
    result = []
    for n in numbers:
        for f in factors(n):
            print(f)
            pass
        result.append(f)
    return result

print(liczby([4,25,46,33]))
