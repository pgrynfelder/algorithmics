def dnacount(dna):
    return " ".join([str(x) for x in [dna.count('A'), dna.count('C'), dna.count('G'), dna.count('T')]])

def rna(dna):
    return dna.replace('T', 'U')

def rcompl(dna):
    dna = dna.upper()
    replacements = {'A': 't',
                    'T': 'a',
                    'G': 'c',
                    'C': 'g'}
    for key in replacements:
        dna = dna.replace(key, replacements[key])
    return dna.upper()[::-1]

def rabbits(n, k):
	if n == 1 or n == 2: return 1;
	rabbit_pairs = rabbits(n-2, k) * k + rabbits(n-1, k)
	return rabbit_pairs

def gc(*sets):
    if not sets:
        sets = []
        while True:
            line = input('')
            if line == '':
                break
            sets.append(line)
    sets = "".join(sets).split('>')[1:]
    sets = dict(zip([x[:13] for x in sets], [x[13:] for x in sets]))

    biggest = (None, 0)
    for name in sets:
        percentage = (sets[name].count('G') + sets[name].count('C')) / len(sets[name]) * 100
        if percentage > biggest[1]:
            biggest = (name, percentage)
    return "\n".join(str(x) for x in biggest)

def mutations(*sets):
    if not sets:
        sets = []
        while True:
            line = input('')
            if line == '':
                break
            sets.append(line)
    result = 0
    for x,y in zip(sets[0], sets[1]):
        if x != y:
            result += 1
    return result

def prb():
    d, m, r = (int(x) for x in input().split(" "))
    total = d+m+r
    chanced = d / total
    chancem = m / total * (d/(total - 1) + (m-1)/(total - 1) * 3/4 + r/(total - 1) * 2/4)
    chancer = r / total * (d/(total - 1) + m/(total - 1) * 2/4)
    return chanced + chancem + chancer

def prt():
    gencode = {
    'ATA':'I', 'ATC':'I', 'ATT':'I', 'ATG':'M',
    'ACA':'T', 'ACC':'T', 'ACG':'T', 'ACT':'T',
    'AAC':'N', 'AAT':'N', 'AAA':'K', 'AAG':'K',
    'AGC':'S', 'AGT':'S', 'AGA':'R', 'AGG':'R',
    'CTA':'L', 'CTC':'L', 'CTG':'L', 'CTT':'L',
    'CCA':'P', 'CCC':'P', 'CCG':'P', 'CCT':'P',
    'CAC':'H', 'CAT':'H', 'CAA':'Q', 'CAG':'Q',
    'CGA':'R', 'CGC':'R', 'CGG':'R', 'CGT':'R',
    'GTA':'V', 'GTC':'V', 'GTG':'V', 'GTT':'V',
    'GCA':'A', 'GCC':'A', 'GCG':'A', 'GCT':'A',
    'GAC':'D', 'GAT':'D', 'GAA':'E', 'GAG':'E',
    'GGA':'G', 'GGC':'G', 'GGG':'G', 'GGT':'G',
    'TCA':'S', 'TCC':'S', 'TCG':'S', 'TCT':'S',
    'TTC':'F', 'TTT':'F', 'TTA':'L', 'TTG':'L',
    'TAC':'Y', 'TAT':'Y', 'TAA':'_', 'TAG':'_',
    'TGC':'C', 'TGT':'C', 'TGA':'_', 'TGG':'W'}
    rna = input().replace('U', 'T')
    aslist = []
    for i in range(0,len(rna),3):
        aslist.append(rna[i:i+3])
    aslist = [gencode[e] for e in aslist]
    return "".join(aslist).replace('_', '')

def find(*sets):
    if not sets:
        sets = []
        while True:
            line = input('')
            if line == '':
                break
            sets.append(line)
    string, searched = sets
    result = [0]
    while True:
        i = string.find(searched)
        if i == -1:
            break
        result.append(i+1+result[-1])
        string = string[i+1:]
    return " ".join(str(x) for x in result if x)
        
def mtx(*sets):
    if not sets:
        sets = []
        while True:
            line = input('')
            if line == '':
                break
            sets.append(line)
    sets = "".join(sets).split('>')[1:]
    sets = [x[13:] for x in sets]
    matrix = {'A': [], 'T': [], 'C': [], 'G': []}
    consensus = []
    for s in zip(*sets):
        biggest = (None, 0)
        for nucleo in matrix:
            nucleocount = s.count(nucleo)
            matrix[nucleo].append(str(nucleocount))
            if nucleocount > biggest[1]:
                biggest = (nucleo, nucleocount)
        consensus.append(biggest[0])
    print("".join(consensus) + "\n" + "\n".join("{}: {}".format(nucleo, " ".join(matrix[nucleo])) for nucleo in matrix))
    
