from __future__ import absolute_import, division, print_function, unicode_literals

import numpy as np

import sklearn.utils as skl
import tensorflow as tf

# tf.enable_eager_execution()
tf.keras.backend.clear_session()

print("Version: ", tf.__version__)
print("Eager mode: ", tf.executing_eagerly())
print("GPU is", "available" if tf.config.experimental.list_physical_devices("GPU") else "NOT AVAILABLE")

import testing
import preprocessing as pp
# testing.generate()
tests = [1, 2, 3, 4]
titles = dict(Sienkiewicz = np.array([0,0,1]), Mickiewicz = np.array([1,0,0]), Prus = np.array([0,1,0]))

examples = []
labels = []

for n in tests:
    for j in range(0, 10):
        j = str(j)
        j = j.zfill(3)
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: examples.append(
                    np.array(
                    pp.resize(
                    pp.hash(
                    pp.stem(
                    pp.depunctuate(
                    line.lower())))), dtype=np.float32))

        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                labels.append(titles[a.replace('\n', '')])

DATASET_SIZE = len(examples)
examples, labels = skl.shuffle(examples, labels, random_state=0)

train_examples = np.array(examples[:DATASET_SIZE//2], np.float32)
train_labels = np.array(labels[:DATASET_SIZE//2], np.float32)
val_examples = np.array(examples[DATASET_SIZE//2:], np.float32)
val_labels = np.array(labels[DATASET_SIZE//2:], np.float32)

print("Data preparation finished")

# ds = tf.data.Dataset.from_tensor_slices((train_examples, train_labels))
# # ds = tf.data.Dataset((train_examples, train_labels))
# ds = ds.shuffle(DATASET_SIZE).batch(1)
#
# train = ds.take(DATASET_SIZE//2)
# val = ds.skip(DATASET_SIZE//2)
model = tf.keras.Sequential([
    tf.keras.layers.Dense(100, activation="sigmoid"),
    tf.keras.layers.Dense(20, activation="sigmoid"),
    tf.keras.layers.Dense(20, activation="sigmoid"),
    tf.keras.layers.Dense(20, activation="sigmoid"),
    tf.keras.layers.Dense(3, activation="softmax")
])

model.compile(optimizer='adam',
            # loss='sparse_categorical_crossentropy',
            loss=tf.keras.losses.MeanSquaredError(),
            metrics=['accuracy'])

model.fit(train_examples, train_labels, epochs=1000, validation_data=(val_examples, val_labels))

model.summary()
model.save('my_model.h5')