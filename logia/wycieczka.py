class defaultdict(dict):
    def __init__(self, default_factory, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.default_factory = default_factory

    def __missing__(self, key):
        self[key] = self.default_factory()
        return self[key]


def dijakstra(times):
    from_source = defaultdict(lambda: float("+inf"))
    from_source['d'] = 0
    neighboring = defaultdict(lambda: defaultdict(lambda: float("+inf")))
    queue = set()
    for v, u, distance in times:
        neighboring[v][u] = distance
        # basic
        queue |= {u, v}
    # print(queue)
    while queue:
        min_dist = float("+inf")
        # finding queued node with smallest distance from source
        for v in queue:
            if from_source[v] <= min_dist:
                min_dist = from_source[v]
                min_v = v
        # deleting the node from queue
        queue -= {min_v}
        # registering distances for it's children (aka neighboring nodes)
        for u in neighboring[min_v]:
            alt = from_source[min_v] + neighboring[min_v][u]
            if from_source[u] > alt:
                from_source[u] = alt
        # print(queue)
        # print(from_s)
    return from_source['s']

def bfs(times):
    neighboring = defaultdict(lambda: defaultdict(lambda: float("+inf")))
    from_source = defaultdict(lambda: float("+inf"))
    for v, u, distance in times:
        neighboring[v][u] = distance
    queue = [('d', 0)]
    while queue:
        v, d = queue.pop(0)
        from_source[v] = min(from_source[u], d)
        for u, u_to_v in neighboring[v].items():
            queue.append((u, d + u_to_v))
    return from_source['s']


if __name__ == '__main__':
    tests = [[['d', 'p1', 10], ['d', 'p2', 20], ['p1', 'p3', 20], [
          'p2', 'p3', 5], ['p2', 's', 30], ['p3', 's', 5]]]
    for x in tests:
        print(dijakstra(x))
        print(bfs(x))
