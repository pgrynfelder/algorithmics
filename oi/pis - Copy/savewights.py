from __future__ import absolute_import, division, print_function, unicode_literals
import csv
import numpy as np
from collections import OrderedDict
from math import sqrt
import tensorflow as tf

model = tf.keras.models.load_model("relu59x20x3.h5")
weights = [x.numpy() for x in model.weights]

w1 = weights[0]
w2 = weights[2]
t1 = weights[1]
t2 = weights[3]

def wformat(w):
    result = "{"
    for x in w:
        result += "{"
        for y in x:
            toadd = "{0:.3f}".format(y).strip("0")
            if (len(toadd) > 4):
                toadd = "{0:.2f}".format(y).strip("0")
            if toadd == '.': toadd = "0"
            result += toadd + ","
        result = result.strip(",")
        result += "},"
    result = result.strip(",")
    result += "}"
    return result

def tformat(t):
    result = "{"
    for y in t:
        toadd = "{0:.3f}".format(y).strip("0")
        if (len(toadd) > 4):
            toadd = "{0:.2f}".format(y).strip("0")
        if toadd == '.': toadd = "0"
        result += toadd + ","
    result = result.strip(",")
    result += "}"
    return result

