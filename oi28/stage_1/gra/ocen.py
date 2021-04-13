import os
from posix import listdir

dir = os.path.join(os.getcwd(), "tests")

tests = [
    os.path.join(dir, filename[:-3])
    for filename in os.listdir(dir)
    if filename.endswith(".in")
]
for test in tests:
    print(test)
    os.system(f"./gra.e < {test}.in > out")
    os.system(f"diff out {test}.out")