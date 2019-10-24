import os

def generate():
    os.system("mkdir tests")
    os.chdir("tests")
    for i in range(1, 5):
        os.system(f"python ../files/pistestgen.py {i} {i} ../files")
if __name__ == "__main__":
    generate()
