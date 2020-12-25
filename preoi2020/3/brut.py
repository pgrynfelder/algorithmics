input()
t = [int(x) for x in input().split()]
q = int(input())
for i in range(q):
    (a, b, c) = tuple(int(x) for x in input().split())
    available = {0}
    for x in t[a:b+1]:
        toadd = set()
        for y in available:
            toadd |= {y + x}
        available |= toadd
    if c in available:
        print("TAK")
    else:
        print("NIE")
