from __future__ import absolute_import, division, print_function, unicode_literals

import numpy as np

import tensorflow as tf

import tensorflow_hub as hub
import tensorflow_datasets as tfds

tf.enable_eager_execution()
tf.keras.backend.clear_session()

print("Version: ", tf.__version__)
print("Eager mode: ", tf.executing_eagerly())
print("Hub version: ", hub.__version__)
print("GPU is", "available" if tf.config.experimental.list_physical_devices("GPU") else "NOT AVAILABLE")

import testing
import preprocessing as pp
# testing.generate()
tests = [1]
titles = dict(Sienkiewicz = np.array([0,0,1]), Mickiewicz = np.array([1,0,0]), Prus = np.array([0,1,0]))
for n in tests:
    train_examples = []
    train_labels = []
    for j in range(0, 10):
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: train_examples.append(pp.hash(pp.stem(pp.depunctuate(line.lower()))))

        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                train_labels.append(titles[a.replace('\n', '')])
            
train_examples = np.array(train_examples, np.float64)
train_labels = np.array(train_labels, np.float64)

# ds = tf.data.Dataset.from_tensor_slices((train_examples, train_labels))

ds = tf.data.Dataset.from_tensor_slices((train_examples, train_labels))
ds.shuffle(1000)
ds = ds.batch(100)

model = tf.keras.Sequential([
    tf.keras.layers.Dense(2000, activation="sgd"),
    tf.keras.layers.Dense(1000, activation="sgd"),
    tf.keras.layers.Dense(500, activation="sgd"),
    tf.keras.layers.Dense(250, activation="sgd"),
    tf.keras.layers.Dense(125, activation="sgd"),
    tf.keras.layers.Dense(3, activation="softmax")
])

model.compile(optimizer='adam',
              # loss='sparse_categorical_crossentropy',
              loss=tf.keras.losses.MeanSquaredError(),
              metrics=['accuracy'])

model.fit(ds, epochs=10000)

model.apply(train_examples)