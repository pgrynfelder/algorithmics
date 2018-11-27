def wyspa(roads):
    half = sum(roads)/2
    mindif = half
    distance = 0
    i = 0; j = 0 # indexy miast, zaczynam niby od tego samego żeby poprawnie naliczać dystans
    while j < len(roads):
    
    # dzieki temu, ze kolko sie zamyka,
    # nie musimy sprawdzac przypadkow przechodzacych przez koniec listy
    # bo abs na koncu sprowadza sie do |half - (calosc - distance)| = |- half + distance| = |half - distance|

        if distance < half: #jak jest za malo, to rozszerzamy
            distance = distance + roads[j]
            j += 1
        else: # jak za duzo, to skracamy
            distance = distance - roads[i]
            i += 1
        mindif = min(mindif, abs(half - distance))
    return int(half - mindif)
