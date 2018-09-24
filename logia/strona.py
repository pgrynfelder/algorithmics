'''class defaultdict(dict):
    def __init__(self, default_factory, *args, **kwargs):
        self.default_factory = default_factory
        super().__init__(self, *args, **kwargs)
    def __missing__(self, key):
        self[key] = self.default_factory()
        return self[key]

def maxu(visits):
    at_second = defaultdict(lambda: 0)
    for visit in visits:
        a, b = visit[0], visit[0] + visit[1]
        for i in range(a, b+1):
            at_second[i] += 1
    max_users = 0
    for second, users in at_second.items():
        max_users = max(max_users, users)
    return max_users'''

def maxu(visits):
    enter, leave = [], []
    for visit in visits:
        a, b = visit[0], visit[0] + visit[1]
        enter.append(a)
        leave.append(b)
    enter.sort()
    leave.sort()
    i, j = 0,0
    max_users = 0
    while i < len(enter) and j < len(leave):
        print(enter[i], leave[j], i - j)
        if enter[i] < leave[j]:
            i += 1
        else:
            j += 1
        max_users = max(max_users, i - j) # obecni userzy to tyle ile weszło - wyszło
    return max_users





if __name__ == '__main__':
    print(maxu([[1,2],[2,3],[1,10],[2,2],[5,5]]))
