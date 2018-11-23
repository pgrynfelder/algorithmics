
#       [[s,t],[2,2]]
def maxu(listaantka):
    rangelist = []
    seconds = 0
    maxcount = 0
    for user in listaantka:
        #print(user[0], user[1])
        lastsecond = user[0] + user[1]
        rangelist.append(range(user[0], lastsecond + 1))
        seconds = max(seconds, lastsecond)
    #print(rangelist)
    #print(seconds)
    for sec in range(seconds):
        count = 0
        for element in rangelist:
            if sec in element:
                count += 1
        maxcount = max(count, maxcount)
    return maxcount

print(maxu([[1,10],[2,8],[3,6]]))
print(maxu([[1,2],[2,3],[1,10],[2,2],[5,5]]))
