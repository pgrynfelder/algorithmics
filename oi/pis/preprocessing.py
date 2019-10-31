import numpy as np

vowels = set("eyuioa")
hash_mod = 2**31-1
hash_base = 1e6 + 133


def depunctuate(text: str) -> str:
    result = []
    text = text.replace('\n', '')
    words = text.split()
    for word in words:
        result_word = ""
        for char in word:
            if char.isalpha() or char.isnumeric():
                result_word += char
        if (result_word):
            result.append(result_word)
    return " ".join(result)


def stem(text: str) -> str:
    result = []
    words = text.split()
    for word in words:
        result_word = ""
        should_add = False
        for i in range(len(word) - 2, -1, -1):
            char = word[i]
            if (char in vowels):
                should_add = True
            if (should_add):
                result_word += char
        if (result_word):
            result.append(result_word[::-1])
    return " ".join(result)


def hash(text: str):
    result = []
    words = text.split()
    for word in words:
        result.append(0)
        for char in word:
            result[-1] = int((result[-1] * hash_base + ord(char)) % hash_mod)
    while (len(result) < 2000):
        result.append(0)
    return np.array(result)