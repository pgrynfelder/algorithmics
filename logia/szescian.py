def obok(n, k):
    def valid(x, y, z):
        if 0 <= x < n and 0 <= y < n and 0 <= z < n:
            return True

    def neighbors(x, y, z):
        result = [(x + 1, y, z),
                  (x - 1, y, z),
                  (x, y + 1, z),
                  (x, y - 1, z),
                  (x, y, z + 1),
                  (x, y, z - 1)]
        return [coords for coords in result if valid(*coords)]
    # l = k - 1
    # l = x + n*y + n^2*z
    i = k - 1
    x = i % n
    y = ((i - x) // n) % n
    z = (i - x - n * y) // (n**2)
    result = []
    for u, v, w in neighbors(x, y, z):
        result.append(u + n * v + n**2 * w + 1)
    return sorted(result)


if __name__ == '__main__':
    print(obok(3, 11))
    print(obok(7, 1))
    print(obok(10, 1000))
