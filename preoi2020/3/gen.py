from random import randint
n = int(1e1)
q = int(1e1)
print(n)
print(" ".join(str(randint(1, int(1e9))) for i in range(n)))
print(q)
for i in range(q):
    a = randint(1, n)
    b = randint(a, n)
    x = randint(1, int(1e4));
    print(a, b, x)
