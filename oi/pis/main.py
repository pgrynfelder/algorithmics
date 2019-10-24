import testing
import preprocessing as pp
import numpy as np
import tensorflow as tf

# testing.generate()
tests = [3]
titles = dict(Sienkiewicz = 2, Mickiewicz = 0, Prus = 1)
for n in tests:
    train_examples = []
    train_labels = []
    
    with open(f"tests/{n}.in") as test:
        for i, line in enumerate(test.readlines()):
            if (i != 0): train_examples.append(pp.hash(pp.stem(pp.depunctuate(line.lower()))))

    with open(f"tests/{n}.out") as result: 
        for a in result.readlines():
            train_labels.append(titles[a.replace('\n', '')])
            

    # print(train_examples[0], train_labels[0])

train_dataset = tf.data.Dataset.from_tensor_slices((train_examples, train_labels))
BATCH_SIZE = 64
SHUFFLE_BUFFER_SIZE = 100

train_dataset = train_dataset.shuffle(SHUFFLE_BUFFER_SIZE).batch(BATCH_SIZE)
print(train_dataset)