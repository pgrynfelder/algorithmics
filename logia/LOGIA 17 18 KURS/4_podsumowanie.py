def getcodes():
    codes = ['●○○○○○', '●○●○○○', '●●○○○○', '●●○●○○', '●○○●○○', '●●●○○○', '●●●●○○', '●○●●○○', '○●●○○○', '○●●●○○', '●○○○●○', '●○●○●○', '●●○○●○', '●●○●●○', '●○○●●○', '●●●○●○', '●●●●●○', '●○●●●○', '○●●○●○', '○●●●●○', '●○○○●●', '●○●○●●', '○●●●○●', '●●○○●●', '●●○●●●', '●○○●●●']
    positions = {0:0,
                 1:3,
                 2:1,
                 3:4,
                 4:2,
                 5:5}
    codes2 = []
    for x in codes:
        toappend = [0,0,0,0,0,0]
        for i in range(len(x)):
            if x[i] == '●':
                toappend[positions[i]] = 1
        toappend = "".join(str(x) for x in toappend)
        codes2.append(toappend)
    print(codes2)
    
def szyfrB(word):
    codes = ['100000', '110000', '100100', '100110', '100010', '110100', '110110', '110010', '010100', '010110', '101000', '111000', '101100', '101110', '101010', '111100', '111110', '111010', '011100', '011110', '101001', '111001', '010111', '101101', '101111', '101011']
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    keydict = dict(zip(alphabet+" ",codes + ['2']))
    return "".join(keydict[x] for x in word)

def deszyfrB(coded):
    codes = ['100000', '110000', '100100', '100110', '100010', '110100', '110110', '110010', '010100', '010110', '101000', '111000', '101100', '101110', '101010', '111100', '111110', '111010', '011100', '011110', '101001', '111001', '010111', '101101', '101111', '101011']
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    keydict = dict(zip(codes + ['222222'], alphabet + " "))
    coded = coded.replace("2", "222222")
    coded = [coded[i:i+6] for i in range(0, len(coded), 6)]
    return "".join(keydict[x] if x in keydict.keys() else "?" for x in coded)

def morse(table):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    signs = '01'
    table = table.replace("\n", "").replace(" ", "").replace("•", "0").replace("—", "1")
    keydict = {" ": ""}
    toappend = ""
    for x in table[::-1]:
        if x in alphabet and toappend == "":
            continue
        elif x in signs:
            toappend += x
        elif x in alphabet and toappend:
            keydict.update({x: toappend[::-1]})
            toappend = ""
    print(keydict)

def szyfrM(word):
    keydict = {' ': '', 'z': '1100', 'm': '11', 'y': '1011', 'l': '0100', 'x': '1001', 'k': '101', 'w': '011', 'j': '0111', 'v': '0001', 'i': '00', 'u': '001', 'h': '0000', 't': '1', 'g': '110', 's': '000', 'f': '0010', 'r': '010', 'e': '0', 'q': '1101', 'd': '100', 'p': '0110', 'c': '1010', 'o': '111', 'b': '1000', 'n': '10', 'a': '01'}
    return "2".join(keydict[x] for x in word)

def deszyfrM(coded):
    keydict = {' ': '', 'z': '1100', 'm': '11', 'y': '1011', 'l': '0100', 'x': '1001', 'k': '101', 'w': '011', 'j': '0111', 'v': '0001', 'i': '00', 'u': '001', 'h': '0000', 't': '1', 'g': '110', 's': '000', 'f': '0010', 'r': '010', 'e': '0', 'q': '1101', 'd': '100', 'p': '0110', 'c': '1010', 'o': '111', 'b': '1000', 'n': '10', 'a': '01'}
    keydict = {v: k for k,v in keydict.items()}
    return "".join(keydict[x] if x in keydict.keys() else "?" for x  in coded.split("2"))

def tetris(blocks):
    width, blocks = blocks[0], blocks[1:]
    row = [0 for _ in range(width)]
    result = 1
    for block in blocks:
        changes = True
        while changes:
            changes = False
            for i in range(block[1], block[1] + block[0]):
                if row[i]:
                    result += 1
                    print(row)
                    row = [0 for _ in range(width)]
                    changes = True
                    break
                else:
                    row[i] += 1
    print(row)
    return result
