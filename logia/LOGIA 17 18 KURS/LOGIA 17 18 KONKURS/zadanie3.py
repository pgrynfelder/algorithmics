def convert(n, number_system_base):
    new = []
    while n:
        rest = n % number_system_base
        new.append(rest)
        n = (n - rest) / number_system_base
    return new

def ile(n):
    return int(sum(convert(n,3)))
