
def napis():
    n = "abc123"
    print(n.isdigit())
    print(n.upper().islower())
    print(n.isalnum())
    print(n.upper().isupper())

def test(n):
    pom = 0
    for zn in str(n):
        pom+=int(zn)
    return 20 > pom > 10 and pom%2 == 1

#for n in [122481, 11111111, 2764, 243112, 117912, 99]:
 #   print(n, test(n))

def test2(x):
    return x%3==0 and x//10==3 and str(x)!=str(x)[::-1] and '0' not in str(x)

n = 0#1
while n:
    if test2(n):
        print(n)
        break
    n+=1

def test3(string):
    topass = 2
    for x in 'eęyuioóaą':
        if x in string:
            topass -= 1
            break
    if len(string) % 2 == 0:
        topass -= 1
    return topass == 0

print(not (test3("Wanda") or test3("Agnieszka")) and (test3("Antoni") and test3("Zuzia")))
