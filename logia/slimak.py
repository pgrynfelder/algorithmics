class defaultdict(dict):
    def __init__(self, default_factory, *args, **kwargs):
        self.default_factory = default_factory
        super().__init__(self, *args, **kwargs)

    def __missing__(self, key):
        self[key] = self.default_factory()
        return self[key]


def spiralize(word):
    directions = [(0, +1), (+1, 0), (0, -1), (-1, 0)]
    direction = 0
    spiral = defaultdict(lambda: defaultdict(lambda: ""))

    def can_change_dir():
        alt = (direction + 1) % 4
        u, v = x + directions[alt][0], y + directions[alt][1]
        return spiral[u][v] == ""

    x, y = 0, 0
    min_x, min_y, max_x, max_y = 0, 0, 0, 0
    for letter in word:
        spiral[x][y] = letter
        min_x = min(min_x, x)
        min_y = min(min_y, y)
        max_x = max(max_x, x)
        max_y = max(max_y, y)
        if can_change_dir():
            direction = (direction + 1) % 4
        x, y = x + directions[direction][0], y + directions[direction][1]
    return spiral, min_x, min_y, max_x, max_y


def szyfr(words):
    result = []
    for word in words:
        word_result = []
        spiral, min_x, min_y, max_x, max_y = spiralize(word)
        for i in range(max_x, min_x - 1, -1):
            word_result.append("".join([spiral[i][j] for j in range(max_y, min_y - 1, -1)]))
        word_result = "".join(word_result)
        result.append(word_result)
    return result


szyfr(["konkurs"])  # , "logia"])
