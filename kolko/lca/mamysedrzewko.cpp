#include<bits/stdc++.h>

using namespace std;

/* mamy se drzewko
 * delte rzeki dokladniej
 * stefan se wplywa jednym odnozem
 * i wyplywa jakims innym
 * i checemy wiedziec jak dluga jest trasa miedzy nimi
 *
 * precomputing odleglosci od korzenia
 * nie chcemy dfs ani nic bo ma byc szybciej niz liniowo
 * chcemy sie uberszybko do jakichs wyzszych wierzcholkow dostawac
 * 
 * zalozmy ze chcemy se o 6 w gore skoczyc
 * 6 dec = 110 bin = 100 + 10 bin
 * mozemy se precomputing skokow o potegi dwojki dla kazdego wiercholka zrobic
 * gdyby zrobic dla kazdej odleglosci preprocessing to pamiec ded
 * i to nam pozwala skakac w logu
 *
 * dobra czyli juz szukamy tej drogi
 * idziemy do nizszego i skaczemy na poziom tego drugiego
 * teraz binsearchem jakims dziwnym
 *
 * 
 * 
 * root
 * |
 * cos
 * |
 * LCA
 * |\
 * | \
 * |  \
 * |   \
 * 1    2
 *  
 * zalozmy ze to lca jest jakos 7 wyzej
 * sprawdzamy se 2^max niech = 32 dosiegamy
 * 16 dosiegamy
 * 8 dosiegamy
 * 4 nie dosiegamy
 *
 * to sie przyblizamy o 4 
 * // 4 wiemy ze dosiegamy
 * 2 nie dosiegamy
 *
 * to sie przyblizamy o 2
 * // 2 wiemy ze dosiegamy
 * 1 dosiegamy
 * 0 nie dosiegamy
 *
 * to sie przyblizamy o 1
 * // 0 wiemy ze dosiegamy ELO
 *
 */

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
