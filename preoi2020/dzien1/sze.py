from math import sqrt, ceil, floor

n = int(1e5)
k = floor(n ** (1 / 3))

visited = [-1 for i in range(n + 1)]
visited[0] = 0
for i in range(1, k + 1):
    toadd = i ** 3
    j = 0
    # print(i)
    while j + toadd <= n:
        # print(j + toadd)
        if -1 < visited[j] and visited[j] < i and visited[j + toadd] == -1:
            visited[j + toadd] = i
        j += 1

res = [i for i, x in enumerate(visited) if x >= 0]
print(len(res))