from random import randint
# n = random.randint(1,int(3e5))
N = int(1e3)
K = int(1e9)
n = randint(1, N)
k = randint(1, K)
print(n, k)
print(" ".join([str(randint(1, K))for _ in range(n)]))