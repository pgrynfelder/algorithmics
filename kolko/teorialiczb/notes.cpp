#include<bits/stdc++.h>

using namespace std;

/* 
 * sito
 * 
 * rozklad na czynnki pierwsze z sita
 * idac po sicie ustwiamy numer z ktorego do danej komorki doszlismy if is_set pass
 *
 * i potem idziemy od tej liczby w tyl
 * wracajac sie poprzez dzielenie przez przypisana liczbe
 *
 *
 * algorytm euklidesa
 * gcd(a, b) = gcd(b, a mod b)
 * 
 * fun fact to tez dziala dla fib
 * gcd(F(a), F(b)) = gcd(F(b), F(a mod b))
 *
 * rozszerzony algorytm euklidesa
 *
 * ax + by = gcd(a, b)
 * jakie x, y będą działać???
 *
 * przyklad
 * 21 15
 * 21 mod 15 = 6 = 1 * 21 + -1 * 15
 * 15 mod 6 = 3 = -2 * 21 + 3 * 15
 *
 * przyklad 2
 * 42 50
 * 50 mod 42 = 8 = 1 * 50 + -1 * 42
 * 42 mod 8 = 2 = -5 * 50 + (1+5) * 42
 *
 * chinskie twierdzenie o resztach
 *
 * istnieje jedno rozwiazanie ukladu kongruencji
 * x === r1 mod n1
 * x === r2 mod n2
 * ...
 * x === ri mod ni
 *
 * to istnieje jedno rozwiazanie x < n1 * n2 * ... * ni
 *
 *
 * 0 = 5b + 2 - 3a - 1
 * 3a + 1 = 5b + 2
 * 3a = 5b + 1
 *
 * 5b + 2 = 7c + 3
 * 5b = 7c + 1
 *
 * 7c + 3 = 3a + 1
 * 7c + 2 = 3a
 *
 *
 *
 */


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
