(n, m) = (int(x) for x in input().split(' '))
word = input()
text = input()
result = set()
text = text + "&" * (n+7)
for k in range(1,n+1):
    # print(k)
    for i in range(m):
        # print(i)
        if word[0:k] == text[i:i+k]:
            # print("found prefix")
            for j in range(i+k, m+1):
                if word[k:n] == text[j:j+n-k]:
                    # print("found suffix")
                    if text[i+k-1:j].count(text[i+k-1]) == j - i - k + 1:
                        # print ("valid match")
                        result.add(i+1)
print(len(result))
print(" ".join(str(x) for x in sorted(list(result))))

