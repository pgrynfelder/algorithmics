from __future__ import absolute_import, division, print_function, unicode_literals

import numpy as np

import tensorflow as tf

import tensorflow_hub as hub
import tensorflow_datasets as tfds

sess = tf.Session(config=tf.ConfigProto(log_device_placement=True))
tf.enable_eager_execution()
tf.keras.backend.clear_session()

print("Version: ", tf.__version__)
print("Eager mode: ", tf.executing_eagerly())
print("Hub version: ", hub.__version__)
print("GPU is", "available" if tf.config.experimental.list_physical_devices("GPU") else "NOT AVAILABLE")

import testing
import preprocessing as pp
# testing.generate()
tests = [1,2,3,4]
titles = dict(Sienkiewicz = np.array([0,0,1]), Mickiewicz = np.array([1,0,0]), Prus = np.array([0,1,0]))
for n in tests:
    train_examples = []
    train_labels = []
    for j in range(0, 100):
        j = str(j)
        j = j.zfill(3)
        with open(f"tests/{n}{j}.in") as test:
            for i, line in enumerate(test.readlines()):
                if i != 0: train_examples.append(
                    np.array(
                    pp.resize(
                    pp.hash(
                    pp.stem(
                    pp.depunctuate(
                    line.lower())))), dtype=np.float64))

        with open(f"tests/{n}{j}.out") as result: 
            for a in result.readlines():
                train_labels.append(titles[a.replace('\n', '')])
            
train_examples = np.array(train_examples, np.float64)
train_labels = np.array(train_labels, np.float64)

DATASET_SIZE = len(train_examples)

print("Data preparaton finished")

with tf.device('/GPU:0'):

    ds = tf.data.Dataset.from_tensor_slices((train_examples, train_labels))

    ds = ds.shuffle(DATASET_SIZE).batch(10)

    train = ds.take(DATASET_SIZE//20)
    val = ds.skip(DATASET_SIZE//20)
    model = tf.keras.Sequential([
    tf.keras.layers.Dense(100, activation="sigmoid"),
    tf.keras.layers.Dense(20, activation="sigmoid"),
    tf.keras.layers.Dense(20, activation="sigmoid"),
    tf.keras.layers.Dense(3, activation="softmax")
    ])

    model.compile(optimizer='adam',
                # loss='sparse_categorical_crossentropy',
                loss=tf.keras.losses.MeanSquaredError(),
                metrics=['accuracy'])

    model.fit(train, epochs=1000, validation_data=val)

    model.summary()
    model.save('my_model.h5')