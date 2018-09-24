def kulki(unsorted):
    z_wrong = 0
    c_wrong = 0
    for i, ball in enumerate(unsorted):
        if i % 2 == 1 and ball == "c":
            c_wrong += 1
        elif i % 2 == 0 and ball == "z":
            z_wrong += 1
    return min(c_wrong, z_wrong)


if __name__ == '__main__':
    print(kulki("czczczzz"))
    print(kulki("czczzczz"))
