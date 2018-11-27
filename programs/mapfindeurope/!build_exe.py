import os

def main(build_com="pyinstaller main.py --onefile --name=MapFind2"):
    print("::Running pyinstaller::")
    os.system(build_com)
    print(":::Done:::")
    os.system("pause")

if __name__ == "__main__":
    main()