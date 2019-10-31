import os

def generate():
    os.system("mkdir tests")
    os.chdir("tests")
    for i in range(1, 5):
        for j in range(0, 10):
            os.system(f"python3 ../files/pistestgen.py {i} {i}{j} ../files")
        
if __name__ == "__main__":
    generate()
