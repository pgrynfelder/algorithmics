import subprocess
import os

os.system("./ukl.e < 1.in > comparison1")
for i in range(100000000000):
    print(i)
    # subprocess.call()
    # subprocess.call([], int("inf"), "./ukl.e", "in.1", "kurwa.out")
    os.system("./ukl.e < 1.in > comparison2")
    if os.system("diff comparison1 comparison2 -bwe"):
        break
    