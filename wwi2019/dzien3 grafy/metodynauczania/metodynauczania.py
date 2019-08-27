import itertools
k = int(input().split(' ')[1])
q = [int(x) for x in input().split(' ')]
all = sorted([sum(p) for p in itertools.product(q, repeat=3)])
print(all[k-1])