def range_sum(ranges):
    ranges = sorted(ranges)
    for i in range(len(ranges) - 1):
        if ranges[i][1] >= ranges[i + 1][0] - 1:
            ranges[i + 1] = [ranges[i][0], max(ranges[i][1], ranges[i + 1][1])]
            ranges[i] = None
    return [x for x in ranges if x is not None]


def range_common(ranges):
    ranges = sorted(ranges)
    for i in range(len(ranges) - 1):
        if ranges[i][1] >= ranges[i + 1][0]:
            ranges[i + 1] = [ranges[i + 1][0],
                             min(ranges[i][1], ranges[i + 1][1])]
            ranges[i] = None
        else:
            return []
    return [x for x in ranges if x is not None]


def query2range(query, k):
    if query[1] == "m":
        return [1, query[0] - 1]
    elif query[1] == "w":
        return [query[0] + 1, k]
    elif query[1] == "r":
        return [query[0], query[0]]


def jakie(k, pytania):
    k -= 1
    result = []
    for i in range(-1, len(pytania)):
        if i == -1:
            ranges = [query2range(x, k) for x in pytania]
            result.append(range_common(ranges))
        else:
            if pytania[i][1] == "m":
                pytania2 = pytania.copy()
                pytania2[i] = [pytania2[i][0] - 1, "w"]
                ranges = [query2range(x, k) for x in pytania2]
                result.append(range_common(ranges))
            elif pytania[i][1] == "w":
                pytania2 = pytania.copy()
                pytania2[i] = [pytania2[i][0] + 1, "m"]
                ranges = [query2range(x, k) for x in pytania2]
                result.append(range_common(ranges))
            elif pytania[i][1] == "r":
                pytania3, pytania4 = pytania.copy(), pytania.copy()
                pytania3[i][1], pytania4[i][1] = "m", "w"
                ranges3 = [query2range(x, k) for x in pytania3]
                result.append(range_common(ranges3))
                ranges4 = [query2range(x, k) for x in pytania4]
                result.append(range_common(ranges4))
    result2 = []
    for x in result:
        for y in x:
            result2.append(y)
    print(result2)
    return range_sum(result2)


if __name__ == '__main__':
    print(jakie(10, [[5, 'm'], [2, 'w'], [4, 'm'], [1, 'w']]))
    #print(jakie(10, [[5, 'm'], [2, 'w'], [1, 'w'], [6, 'r']]))
    #print(range_common([[1,2], [2,3], [3,4]]))
