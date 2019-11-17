import numpy as np
from collections import defaultdict


P = int(1e6+7)
MOD = int(1e9+7)

# unset = float("inf")
unset = 0

vowels = set("eyuioa")

def h(s: str):
    current = 0
    for c in s:
        current = (current * P + ord(c)) % MOD;
    return current

def process(s: str):
    t = np.full(59, 0, dtype=np.float)
    t[55] = len(s)
    s = s + '^^^'
    words = defaultdict(lambda: 0)
    t[56] = 0
    t[57] = 0
    upper_char_dist = 0;
    upper_word_dist = 0;
    upper_char_distances = []
    upper_word_distances = []
    word_lenght = 0
    word_lengths = []
    sentence_char_length = 0
    sentence_word_length = 0
    sentence_char_lengths = []
    sentence_word_lengths = []
    word_hash = 0
    for i in range(len(s) - 2):
        c = s[i]
        process_word = True
        process_sentence = False
        # characterwise
        if c.isalpha(): 
            t[0] += 1
            t[ord(c.lower()) - ord('a') + 29] += 1
            process_word = False
            word_lenght += 1
            word_hash = ((P * word_hash) + ord(c.lower())) % MOD;
        if c.isupper(): 
            t[1] += 1
            upper_char_distances.append(upper_char_dist)
            upper_word_distances.append(upper_word_dist)
            upper_char_dist = 0
            upper_word_dist = 0
        if c.isdigit(): 
            t[2] += 1
        if c == ' ': 
            t[3] += 1
        if c == '.':
            process_sentence = True
            t[4] += 1
            if s[i+1] == '.' and s[i+2] == '.':
                t[5] += 1
        if c == ',':
            t[6] += 1
        if c == ';':
            t[7] += 1
        if c == ':':
            t[8] += 1
        if c == '"':
            t[9] += 1
        if c == '-':
            t[10] += 1
        if c == '?':
            process_sentence = True
            t[11] += 1
        if c == '!':
            process_sentence = True
            t[12] += 1
        if c.lower() == 'u':
            if s[i+1].lower() == 's':
                t[58] += 1

        sentence_char_length += 1
        upper_char_dist += 1

        if c == '^':
            process_sentence = True
        # wordwise
        if process_word and word_lenght != 0:
            t[56] += 1

            if word_hash == 325955471:
                t[13] += 1
            if word_hash == 105:
                t[14] += 1
            if word_hash == 992934780:
                t[15] += 1
            if word_hash == 97:
                t[16] += 1

            upper_word_dist += 1
            sentence_word_length += 1
            
            word_lengths.append(word_lenght)
            # print(word_hash)
            words[word_hash] += 1;
            word_lenght = 0
            word_hash = 0

        # sentencewise
        if process_sentence and sentence_word_length != 0:
            t[57] += 1

            sentence_char_lengths.append(sentence_char_length)
            sentence_word_lengths.append(sentence_word_length)
            sentence_char_length = 0
            sentence_word_length = 0

    # whole text

    t[17] = len(words)
    t[18] = sum(1 for x in words.keys() if words[x] == 1)

    t[19] = np.average(word_lengths)
    t[20] = np.std(word_lengths)
    t[21] = np.average(sentence_char_lengths)
    t[22] = np.std(sentence_char_lengths)
    t[23] = np.average(sentence_word_lengths)
    t[24] = np.std(sentence_word_lengths)


    if (len(upper_char_distances)):
        t[25] = np.average(upper_char_distances)
        t[26] = np.std(upper_char_distances)
    else:
        t[25] = unset
        t[26] = unset
    
    if (len(upper_word_distances)):
        t[27] = np.average(upper_word_distances)
        t[28] = np.std(upper_word_distances)
    else:
        t[27] = unset
        t[28] = unset
    
    # normalize
    
    for x in range(0, 13):# [0, 1, 2, 3, 4, 8, 7, 10, 6, 9, 5]:
        t[x] /= t[55]
    for x in range(29, 55):
        t[x] /= t[55]
    for x in range(13,19): #[11, 12, 13, 14, 15, 16]:
        t[x] /= t[56]
    t[58] /= t[56]

    return t


translador = dict()
def translate(arr):
    if len(translador) != len(arr):
        with open("labels.txt") as f:
            for i, line in enumerate(f.readlines()):
                translador[i] = line.strip("\n")
    for i in range(len(arr)):
        print(f"{translador[i]}: {arr[i]},")

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        process(input())