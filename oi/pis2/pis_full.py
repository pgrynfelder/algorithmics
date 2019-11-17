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
    length = len(s)
    s = s + '^^^'
    words = defaultdict(lambda: 0)
    t = defaultdict(lambda: 0)
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
    for i in range(length + 1):
        c = s[i]
        process_word = True
        process_sentence = False
        # characterwise
        if c.isalpha(): 
            t["alpha"] += 1
            process_word = False
            word_lenght += 1
            word_hash = ((P * word_hash) + ord(c.lower())) % MOD;
        if c.isupper(): 
            t["upper"] += 1
            upper_char_distances.append(upper_char_dist)
            upper_word_distances.append(upper_word_dist)
            upper_char_dist = 0
            upper_word_dist = 0
        if c.isdigit(): 
            t["digits"] += 1
        if c == ' ': 
            t["white"] += 1
        if c == '.':
            process_sentence = True
            t["dots"] += 1
            if s[i+1] == '.' and s[i+2] == '.':
                t["tridots"] += 1
        if c == ',':
            t["commas"] += 1
        if c == ';':
            t["semicolons"] += 1
        if c == ':':
            t["colons"] += 1
        if c == '"':
            t["quotations"] += 1
        if c == '-':
            t["dashes"] += 1
        if c == '?':
            process_sentence = True
            t["question"] += 1
        if c == '!':
            process_sentence = True
            t["exclamation"] += 1

        sentence_char_length += 1
        upper_char_dist += 1

        if c == '^':
            process_sentence = True
        # wordwise
        if process_word and word_lenght != 0:
            t["words"] += 1

            if word_hash == 325955471:
                t["tudziez"] += 1
            if word_hash == 105:
                t["i_spojnik"] += 1
            if word_hash == 992934780:
                t["oraz"] += 1
            if word_hash == 97:
                t["a_spojnik"] += 1

            upper_word_dist += 1
            sentence_word_length += 1
            
            word_lengths.append(word_lenght)
            # print(word_hash)
            words[word_hash] += 1;
            word_lenght = 0
            word_hash = 0

        # sentencewise
        if process_sentence and sentence_word_length != 0:
            t['sentences'] += 1

            sentence_char_lengths.append(sentence_char_length)
            sentence_word_lengths.append(sentence_word_length)
            sentence_char_length = 0
            sentence_word_length = 0

    # whole text

    t["average_word_length"] = np.average(word_lengths)
    t["std_word_length"] = np.std(word_lengths)
    t["average_sentence_char_length"] = np.average(sentence_char_lengths)
    t["std_sentence_char_length"] = np.std(sentence_char_lengths)
    t["average_sentence_word_length"] = np.average(sentence_word_lengths)
    t["std_sentence_word_length"] = np.std(sentence_word_lengths)


    if (len(upper_char_distances)):
        t["average_upper_char_distance"] = np.average(upper_char_distances)
        t["std_upper_char_distance"] = np.std(upper_char_distances)
    else:
        t["average_upper_char_distance"] = unset
        t["std_upper_char_distance"] = unset
    
    if (len(upper_word_distances)):
        t["average_upper_word_distance"] = np.average(upper_word_distances)
        t["std_upper_word_distance"] = np.std(upper_word_distances)
    else:
        t["average_upper_word_distance"] = unset
        t["std_upper_word_distance"] = unset
    t["unique"] = len(words)
    t["legomena"] = sum(1 for x in words.keys() if words[x] == 1)
    
    # normalize
    
    for x in ["alpha", "upper", "digits", "white", "dots", "colons", "semicolons", "dashes", "commas", "quotations", "tridots", "question", "exclamation"]:
        t[x] /= length
    for x in ["tudziez", "i_spojnik", "oraz", "a_spojnik", "unique", "legomena"]:
        t[x] /= t["words"]

    return t