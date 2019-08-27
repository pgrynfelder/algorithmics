import random

n = random.randint(1, 100)
print(n)
print(' '.join(str(random.randint(1, 100)) for i in range(n)))
m = random.randint(1, 100)
print(m)
print(' '.join(str(random.randint(1, 100)) for i in range(m)))
