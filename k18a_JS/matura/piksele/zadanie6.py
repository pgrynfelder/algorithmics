def xd(t, val, x, y):
        if not (0 <= x < len(t[0]) and 0 <= y < len(t)):
            return False
        return abs(val - t[y][x]) > 128

def zadanie6():
    with open("dane.txt", "r") as f:
        t = [[int(y) for y in x.split(" ")] for x in f.read().split("\n") if x != '']

    lightest = 0
    darkest = 255
    result2 = 0
    result3 = 0
    result4 = 0
    for y in range(len(t)):
        lightest = max(max(t[y]), lightest)
        darkest = min(min(t[y]), darkest)
        if t[y] != t[y][::-1]:
            result2 += 1
        for x in range(len(t[0])):
            v = t[y][x]
            if xd(t, v, x+1, y) or xd(t, v, x-1, y) or xd(t, v, x, y+1) or xd(t, v, x, y-1):
                result3 += 1;
    for x in range(len(t[0])):
        current = 1
        for y in range(len(t)-1):
            if t[y][x] == t[y+1][x]:
                current += 1
            else:
                current = 1
            result4 = max(result4, current)
            

    with open("wyniki6.txt", "w") as f:
        f.write(f"4.1 {lightest} {darkest}\n")
        f.write(f"4.2 {result2}\n")
        f.write(f"4.3 {result3}\n")
        f.write(f"4.4 {result4}\n")


if __name__ == "__main__":
    zadanie6()
