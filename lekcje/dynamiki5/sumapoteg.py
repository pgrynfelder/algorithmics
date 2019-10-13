def s(n, k):
    return sum(x**k for x in range(n+1))

if __name__ == "__main__":
    i = input().split(" ")
    n = int(i[0]); k = int(i[1])
    print(s(n, k))