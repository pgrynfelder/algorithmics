def ileod(a):
    length = len(a)
    b = "".join([str(x % 2) for x in range(1, length + 1)])
    if int(b, base=2) > int(a, base=2):
        b = "".join([str(x % 2) for x in range(1, length)])
    return bin(int(a, base=2) - int(b, base=2))[2:]

if __name__ == '__main__':
    tests = ['101', '111', '1101']
    for test, result in zip(tests, map(ileod, tests)):
        print("test: {}\n result: {}".format(test, result))
