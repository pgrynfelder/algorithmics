def isInBoard(n, pos):
    return pos[0] >= 1 and pos[1] >= 1 and pos[0] <= n and pos[1] <= n

def sumTuples(*args):
    sum1 = 0
    sum2 = 0
    for arg in args:
        sum1 = sum1 + arg[0]
        sum2 = sum2 + arg[1]
    return (sum1, sum2)

def lnp(side, row, col):
    pos = (col, row)
    visited = []
    currentdir = 0
    dirlist = ['right','up','left' ,'down']
    dirs = {'right': (+1, 0),
            'down': (0, -1),
            'left': (-1, 0),
            'up': (0, +1)}
    running = True
    visited.append(pos)
    while running:
        toadd = dirs[dirlist[currentdir]]
        if isInBoard(side, sumTuples(pos, toadd)) and (not sumTuples(pos, toadd) in visited):
            pos = sumTuples(pos, toadd)
            visited.append(pos)
        else:
            print("Fail 1:", sumTuples(pos, toadd))
            currentdir = (currentdir + 1) % 4
            toadd = dirs[dirlist[currentdir]]
            if isInBoard(side, sumTuples(pos, toadd)) and (not sumTuples(pos, toadd) in visited):
                pos = sumTuples(pos, toadd)
                visited.append(pos)
            else:
                print("Fail 2:", sumTuples(pos, toadd), dirlist[currentdir])
                running = False
        
    return side**2 - len(visited)

print(lnp(4,1,2))
print(lnp(4,3,1))
print(lnp(4,4,4))
#print(sumTuples((2,8),(10,-3)))
