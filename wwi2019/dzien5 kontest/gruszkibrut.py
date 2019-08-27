input()
xd = [int(x) for x in input().split(' ')]
input()
questions = [int(x) for x in input().split(' ')]
for q in questions:
    for i in range(len(xd)+1):
        if i == len(xd):
            print(-1, end=' ')
            break

        if xd[i] >= q:
            xd[i] -= q
            print(i+1, end=' ')
            break
print('\n', end='');
