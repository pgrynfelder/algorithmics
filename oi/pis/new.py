from __future__ import absolute_import, division, print_function, unicode_literals
import csv
import numpy as np
from collections import OrderedDict
from math import sqrt
import tensorflow as tf

# tf.debugging.set_log_device_placement(True)
def depunctuate(text):
    result = []
    for word in text.split():
        newword = ""
        for letter in word:
            if letter.isalpha():
                newword += letter
        if newword: result.append(newword)
    return result


alphabet = "abcdefghijklmnopqrstuvwxyz"
digits = "0123456789"

# authors = {
#     "Mickiewicz": 0,
#     "Prus": 1,
#     "Sienkiewicz": 2
# }

def summarize(text: str) -> OrderedDict:
    text = text.replace("\n", "").replace("...", "^")
    summary = OrderedDict()
    summary["characters"] = len(text)
    summary[";"] = text.count(";")
    summary["..."] = text.count("^")
    summary["."] = text.count(".")
    summary[","] = text.count(",")
    summary["-"] = text.count("-")
    summary['"'] = text.count('"')
    summary[':'] = text.count(':')
    summary['!'] = text.count('!')
    summary['?'] = text.count('?')
    summary["us"] = text.count("us")
    sentences = [x for x in text.split(".") if len(x)]
    for letter in alphabet:
        summary[letter] = text.lower().count(letter)
    # for digit in digits:
    #     summary[digit] = text.count(digit)
    summary["numbers"] = sum(1 for x in text.split() if x.isnumeric())
    text = depunctuate(text)
    summary["sentences"] = len(sentences)
    summary["words"] = len(text);
    summary["letters"] = sum(len(x) for x in text)
    summary["words_unique"] = len(set(x.lower() for x in text))
    summary["words_capitalized"] = sum(1 for x in text if x[0].lower() != x[0])
    summary["mean_word_length"] = summary["letters"] / summary["words"]
    summary["standard_deviation_word_length"] = sqrt(
        sum(pow(summary["mean_word_length"] - len(x), 2) for x in text) / summary["words"])
    summary["mean_sentence_length"] = summary["words"] / summary["sentences"]
    summary["standard_deviation_sentence_length"] = sqrt(
        sum(pow(summary["mean_sentence_length"] - len(x.split()), 2) for x in sentences) / summary["sentences"])
    summary["i_spojnik"] = sum(1 for x in text if x.lower() == "i")
    summary["oraz"] = sum(1 for x in text if x.lower() == "oraz")
    summary["tudziez"] = sum(1 for x in text if x.lower() == "tudziez")
    summary["a_spojnik"] = sum(1 for x in text if x.lower() == "a")

    scaled_summary = summary.copy()
    exclusions = {"author",
                  "mean_word_length",
                  "standard_deviation_word_length",
                  "mean_sentence_length",
                  "standard_deviation_sentence_length",
                  "characters"}
    for key in summary.keys():
        if key not in exclusions:
            scaled_summary[key] = summary[key] / summary["characters"]
    return scaled_summary

def dict2vec(summary):
    vector = list()
    exclusions = {"author", "characters"}
    for key, value in zip(summary.keys(), summary.values()):
        if key not in exclusions:
            vector.append(value)
    return np.array(vector, dtype=np.float32)

# books = []
# for i, author in enumerate(("Mickiewicz", "Prus", "Sienkiewicz")):
#     with open(f"files/{author}.txt") as f:
#         text = f.read()
#     books.append(dict2vec(summarize(text)))

# books = np.array(books).flatten()

tests = [1,2,3,4]
# tests = [4]
titles = {
    "Sienkiewicz": np.array([0,0,1]), 
    "Mickiewicz": np.array([1,0,0]), 
    "Prus": np.array([0,1,0])
}

examples = []
labels = []
for n in tests:
    for j in range(0, 10):
        j = str(j)
        j = j.zfill(3)
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: 
                    examples.append(dict2vec(summarize(line)))
        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                labels.append(titles[a.replace('\n', '')])

examples = np.array(examples)
labels = np.array(labels)
DATA_SIZE = examples.shape[1]
test_examples = []
test_labels = []
for n in tests:
    for j in range(10, 12):
        j = str(j)
        j = j.zfill(3)
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: 
                    test_examples.append(dict2vec(summarize(line)))
        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                test_labels.append(titles[a.replace('\n', '')])

test_examples = np.array(test_examples)
test_labels = np.array(test_labels)


tf.keras.backend.clear_session()
model = tf.keras.Sequential([
    tf.keras.layers.Dense(10, input_shape=(50,), activation="sigmoid"),
    tf.keras.layers.Dense(3, activation="softmax")
])
model.compile(
    optimizer='adam',
    loss=tf.keras.losses.CategoricalCrossentropy(),
    metrics=['accuracy']
)
model.fit(examples, labels, epochs=1000, validation_data=(test_examples, test_labels))
model.summary()

model.save("model50x10x3.h5")
