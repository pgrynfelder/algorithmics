import random
n = random.randint(1,5)
m = random.randint(n, 100)
print(f"{n} {m}")

for x in range(n):
    print(random.choice("ab"), end="")
print()
for x in range(m):
    print(random.choice("ab"), end="")
print()