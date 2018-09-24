def kosp(a, b):
    digits = "0123456789"
    a = [(a[i], a[i + 1]) for i in range(0, len(a), 2)]
    b = [(b[i], b[i + 1]) for i in range(0, len(b), 2)]
    #print(a)
    #print(b)
    for i in range(1, min(len(a), len(b))+1):
        if a[-i][0] == b[-i][0]:
            a[-i] = b[-i] = None

    return sum(int(elem[1]) for elem in a + b if elem != None)


print(kosp("D3E5J8", "H3I2E4J6"))
print(kosp("A3T5U6","B4G1Y4"))
