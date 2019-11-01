import os

def generate():
    os.system("mkdir tests")
    os.chdir("tests")
    for i in range(1, 5):
        for j in range(0, 100):
            j = str(j)
            j = j.zfill(3)
            os.system(f"python ../files/pistestgen.py {i} {i}{j} ../files")
        
if __name__ == "__main__":
    generate()
