n, q = input().split()
n = int(n)
q = int(q)
W = list(input())
W.reverse()
Z = list(input())
Z.reverse()
S = str(int("".join(reversed(W))) + int("".join(reversed(Z)))).zfill(n)

for i in range(q):
    inp = input().split()
    if len(inp) == 3:
        c, i, x = inp
        i = int(i)
        if inp[0] == "W":
            W[i - 1] = x
        elif inp[0] == "Z":
            Z[i - 1] = x
        S = str(int("".join(reversed(W))) + int("".join(reversed(Z)))).zfill(n)
    else:
        c, i = inp
        i = int(i)
        print(S[n - i])
