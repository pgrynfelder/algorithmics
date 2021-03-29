n = 2 ** 19 - 1

print(n)
for i in range(1, (n + 1) // 2):
    print(i * 2, i * 2 + 1)
for i in range((n + 1) // 2, n + 1):
    print(0, 0)

print(n - 1)
for i in range((n + 1) // 2, n):
    print(i, i + 1)
    print(i + 1, i)
