import random

n = random.randint(10, 100)
k = random.randint(1,1000)
print(f"{n} {k}")
result = " ".join([str(random.randint(1, 100)) for _ in range(n)])
print(result)