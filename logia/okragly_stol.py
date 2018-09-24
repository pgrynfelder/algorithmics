def ostatni(n, k):
    sitting = [True] * n
    i = 0
    popper = 0
    while sum(sitting) > 1:
        popper = popper + 1 if sitting[i] else popper
        if k == popper:
            sitting[i] = False
            popper = 0
        i = (i + 1) % len(sitting)
    return sitting.index(True) + 1


if __name__ == '__main__':
    print(ostatni(7, 3))
    print(ostatni(6, 2))
    print(ostatni(2, 2))
