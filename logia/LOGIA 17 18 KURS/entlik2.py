def entlik2(a, n):
    if n > 1:
        return 4 * entlik2(a, n-1) + a
    else:
        return 5 * a
