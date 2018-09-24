def maxj(lanterns_grid):
    def lanterns_in_range(x, y):
        result = []
        max_x, max_y = len(lanterns_grid[0]) - 1, len(lanterns_grid) - 1
        # i, i-1, i+1
        for u in range(x - 1, x + 2):
            if u >= 0 and u <= max_x:
                for v in range(y - 1, y + 2):
                    if v >= 0 and v <= max_y:
                        distance = abs(u - x) + abs(v - y)
                        result.append((lanterns_grid[v][u], distance))
        return result
    max_light = 0
    max_j = 0
    max_i = 0
    for j, row in enumerate(lanterns_grid):
        for i, lantern in enumerate(row):
            light = sum(x[0] / (x[1] + 1) for x in lanterns_in_range(i, j))
            if light > max_light:
                max_light = light
                max_j = j
                max_i = i
    return max_j + 1, max_i + 1


if __name__ == '__main__':
    print(maxj([[1, 2, 3, 2], [0, 0, 1, 2]]))
