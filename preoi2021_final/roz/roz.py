import subprocess

for i in range(int(1), int(100)):
    a = subprocess.run(
        ["./roz.e"], input=f"1 {i}", encoding="ascii", capture_output=True
    )
    b = subprocess.run(
        ["./roz36.e"], input=f"1 {i}", encoding="ascii", capture_output=True
    )
    if (a.stdout != b.stdout):
        print(f"ERROR at {i}")
        break