def abc(word, required, k):
    def combgen(word):
        for n in range(2**len(word)):
            yield "".join([word[i]
                           for i, bit in enumerate(bin(n)[2:].zfill(len(word)))
                           if bit == "1"])

    def check(word, required):
        req = [x for x in required][::-1]
        for letter in word:
            if not req:
                break
            elif req[-1] == letter:
                req.pop()
        return not req
    combs = {comb for comb in combgen(word) if check(comb, required)}
    return sorted(list(combs))[k-1]


if __name__ == '__main__':
    print(abc('xabacxy', 'abc', 3))
    print(abc('abebc', 'abc', 5))
