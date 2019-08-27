## Plecak klasyczny

dp[v] = max(dp[v], dp[v - w] + c)

## Zadanie Banknoty (XII OI)
https://sio2.staszic.waw.pl/c/matex_k18_a/p/ban/685/

1. Rozpatrujemy miejsca w plecaku (mod bi)
2. Lecimy po ciagu ramka dlugosci ci jakies deque czy inny set

## 0/1 plecak
n <= 1e6
- ai <= 1e6
- a1 + a2 + a3 + a4 + ... ak <= n
- Czyli mamy max sqrt(n/2) roznych wag, stąd zlozoność O(sqrt(n))
1. Zamienmy zbior przedmiotow na pary {bi, ci}
   - dla C calkowitego = 10, bedzie to 1, 2, 4, 3 (potegi dwojki + reszta)
2. No i wrzucamy na plecak
- Teoretycznie O(sqrt(n) * logn * m), ale sie amortyzuje

Wrzucamy na plaszczyzne bi x log(ci) liczby co 1 od 1 do log(ci). Idąc po wartościach logarytmów zachłannie wrzucamy na plecak od dołu płaszczyzny. (funfact: krokow na poziomie jest <= sqrt(n/2^ci)) Wiec worst case to O(sqrt(n) * m) bo const*(1/2 + 1/4 + 1/8...) itp to const*2 -> const

Jako ze jest to 0/1 plecak, to mozna przyspieszyc napitalacjc na bitsetach, czyli przesuwamy go o x w prawo i or z tym co bylo gdzies tam wczesniej w dp
opt x32/64

## Plecak z przedmiotami o uejdmenanmenj wadze
Ujemne przedmioty liczymy od prawej do lewej

## Maly plecak
Kopiujemy plecak i odwolujemy sie do poprzeniego, jak cos nam sie nie podoba to wypitalamy te warstwe

## Zadanie Cukierki (BOI) Plecak bez jednego
- n <= 100 słoików
- w każdym bi <= 7000 cukierków
- chcemy sprzedac cukierki jak najbardziej w sloikach, jak nie dziala to jeden mozemy modyfikowac ale chcemy go zmodyfikowac minimalnie
1. Wezmy arbitralnie podzielone sloiki na zbiory A B
2. Chcemy znalezc taka wartosc, ze jest to najmniejsza wartosc niebedaca roznica ||A| - |B||
3. Mozemy to policzyc plecakiem, wtedy mamy O(N^3\*B)
4. Ale jednego N mozna wypitolic za pomoca specjalnego plecaka
5. Drzewo od plecaka ktore potrafi cos dodac i wypitolic ostatni element
6. i cyk mamy O(N^2 logN B)

## Zadanie szatnia (XIX OI)

## Plecak na dwa stosy

## Telezazdupy PREOI 2017

## Dodawanie Minkowskiego

A + B = {a + b : a in A, b in B}
- Robimy se wielomiany
  - WA(x) = x^a1 + x^a2 + ...
  - WA(y) = x^b1 + ...
- Mnożymy
- Zauwazmy, ze ai + bi = K <=> x^k in WA * WN != 0