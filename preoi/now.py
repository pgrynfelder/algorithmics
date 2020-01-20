primes = [3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61]

# counter = defaultdict(lambda: 0)
counter = dict()

for x in primes:
    i = 1
    counter[x] = 0
    while i**x <= 1e18:
        counter[x] += 1
        i += 1

print(counter)