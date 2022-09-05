# %%
from subprocess import run, PIPE
import os
import numpy as np
import matplotlib.pyplot as plt
from tqdm import tqdm

FILE = os.path.join(os.getcwd(), "lic.e")
N = int(5e5)

xs = np.arange(N)
ys = np.zeros(N)

for i in tqdm(range(N)):
    xd = run(FILE, input=f"{i} 0 0".encode(), stdout=PIPE)
    ys[i] = len(str(xd.stdout).split())
    

plt.scatter(xs, ys)
plt.savefig("plot.png")
# %%
