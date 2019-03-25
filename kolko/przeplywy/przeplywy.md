# Przepływy

siec przeplywowa = graf skierowany
s - zrodlo
t - ujscie
c - ile wody moze przeplynac przez rure (maks. natezenie, przepustowosc)

przeplyw - przpompowanie wody z e zrodla do ujscia
maksymalny - ile maksymalnie
formalne definicje

E - krawedzie
f: E -> R - przeplyw
All (u,v) in E: f(u,v) <= c(u,v)
All (u,v) in E: f(u,v) = -f(v,u)
All v in V\{s,t}: sum(w in V, f(v, w) = 0)

## ALGOS


**jakis chamski zachlan (Forda-Fulkersona) O(f \* E)**
1. f na poczatku 0
2. dopoki istnieje sciezka powiekszajaca p szukamy jej dfsem\
powiekszam f na p o min(cf) na sciezce
3. tworzymy nowy graf wg tego ponizej

SIEC REZYDUALNA
(G, s, t, c)
z G(V, E) bedziemy tworzyc Gf(V, Ef)  (f - po przeplywie)

(u, v) is in Ef iff ((u, v) in E and f(u, v) < c(u, v)) or ((v,u) in E and  f(v, u) > 0)
czyli bedziemy robic nowe, odwrocone, cofajace krawedzie

All (u,v): cf(u, v) = c(u,v) - f(u,v)

ujemna przepustowosc <=> w druga strone

wiec jak mamy z przepustowoscia 4 sciezke i krawedz tez z 4
4 -> 0
0 -> 4
dla krawedzi 5
5 -> 1
0 -> 4


**Alogrytm Edmondsa-Carpa O(E\*E\*V)**
1. to samo tylko z bfsem, dzieki czemu scizki sa najkrotsze, wiec zrobi sie smieszen

**Algorytm Dinnicka**
todo

**Przeplywy na grafie nieskierowanym**
Tworzymy graf ktory ma kraweedzie skierowane we dwie strony z ok warotsciami
i usuwamy wszystkie cykle dlugosci 2???

**other**
wezmy se graf nieskierowany
zamieniamy wierzcholki na krawedzie, a krawedzie miedzy nimi na krawedzie od poczatku jednego do konca drugiego i vce versa
krawedzie z wierzcholkow niech maja wagi 1, reszta  +inf

*jest se takie twierdzenie ze mozna se pociac z minimalnym kosztem
i to przeciecie to bedzie przeplyw max XD*

*inne twierdzenie:
kazdy przeplyw mozna przedstawic jako jakas sciezke i cykle proste*


**dobra graf nieskierowany**
wezmy se graf nieskierowany
rozbijamy se na skierowany
i idziemy algosem 2.
jak idziemy po krawedzi w druga strone miedzy wirzcholkami gdzie juz bylismy to je wyrzucamy
i to dziala bo tam byl bfs wiec najkrotsze xD

**jak to wykorzystac do skojarzen???**
wezmy se graf dwudzielny
chcemy miec maks skojarzenia
wsszystko sie cisnie na to zeby sobie zrobic taka se mila konstrukcje
mamy zbior V1 i V2 pomiedzy ktorymi chcemy skojarzyc jak to w grafie dwudzielnym zwykle bywa
i zeby zrobic skojarzenia
to skierujmy od V1 do V2 krawedzie (+inf chyba)
zrodlo se doczepiamy do V1 a ujscie do V2 i XD krawedziami 1

**zadans fajny**
mamy graf i chcemy pokryc go cyklami prostymi jak najbardziej

bierzemy wiercholki do V1
i robimy kopie V2
jezeli byla krawedz a->b, to robimy teraz krawedz a->b'
do v1 laczymy s, do v2 t
wszystkie krawedzie dajemy 1

jesli istnieje doskonale skojarzenie
to znaczy ze tworzy nam proste cykle


**DINNICK**

1. bfs chodzimy tylko po sciezkach z przepustowoscia > 0 i numerujemy warstwy
2. puszczamy dfsy ktore ida do nizszej warstwy
3. powtarzamy 1. i 2. do skutku

**Skojarzenia Dinnickiem**
1. zrodlo, ujscie, wszystkie krawedzie na 1
2. i jakies smieszne krawedzie z powrotem od ujscia z v2 do pod v1 i do s
