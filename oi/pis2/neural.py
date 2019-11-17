from __future__ import absolute_import, division, print_function, unicode_literals
import csv
import numpy as np
from collections import OrderedDict
from math import sqrt
import tensorflow as tf

import pis

tests = [1,2,3,4]
# tests = [4]
# tests = [1, 2, 3]
titles = {
    "Sienkiewicz": np.array([0,0,1]), 
    "Mickiewicz": np.array([1,0,0]), 
    "Prus": np.array([0,1,0])
}

examples = []
labels = []
for n in tests:
    for j in range(12, 16):
        j = str(j)
        j = j.zfill(3)
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: 
                    examples.append(pis.process(line.strip("\n")))
        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                labels.append(titles[a.strip("\n")])
examples = np.array(examples)
labels = np.array(labels)

DATA_SIZE = examples.shape[1]

test_examples = []
test_labels = []
for n in tests:
    for j in range(12, 16):
        j = str(j)
        j = j.zfill(3)
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: 
                    test_examples.append(pis.process(line.strip("\n")))
        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                test_labels.append(titles[a.strip("\n")])

test_examples = np.array(test_examples)
test_labels = np.array(test_labels)

tf.keras.backend.clear_session()
model = tf.keras.Sequential([
    tf.keras.layers.Dense(20, input_shape=(DATA_SIZE,), activation="relu"),
    tf.keras.layers.Dense(3, activation="softmax")
])
model.compile(
    optimizer='adam',
    loss=tf.keras.losses.CategoricalCrossentropy(),
    metrics=['accuracy']
)
model.fit(examples, labels, epochs=1000, validation_data=(test_examples, test_labels))
model.summary()

model.save(f"xxxrelu{DATA_SIZE}x20x3.h5")