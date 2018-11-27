def zamiana(lista):
    pom = []
    for i in range(0,len(lista)-1,2):
        pom.append(lista[i+1])
        pom.append(lista[i])
    if len(lista) % 2 == 1: 
        pom.append(lista[-1])
    return pom

#zamiana([1, 2, 3, 4, 5, 6, 7])

def drugi(lista):
    pom1 = lista[0]
    pom2 = lista[0]
    for i in range(len(lista)):
        if lista[i] > pom1:
            pom2 = pom1
            pom1 = lista[i]
        elif lista[i] > pom2:
            pom2 = lista[i]
    return pom2

#print(drugi([3,1]))

def wiekszy(lista):
    pom = []
    for i in range(1,len(lista)-1):
        if lista[i] > lista[i-1]:
            pom.append(lista[i])
    return pom

print(wiekszy([1, 5]))
