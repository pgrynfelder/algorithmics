from subprocess import run
from random import randint

z = 100
inp = f"{z}\n"
for i in range(z):
    n = randint(1, 10)
    m = randint(10, 100)
    inp += f"{n} {m}\n" + " ".join(str(randint(1, m)) for j in range(n)) + "\n"

a = run("./wla.e", input=inp, encoding="ascii", capture_output=True)
# print(a.stdout)
print(a.stderr)
# print(inp)