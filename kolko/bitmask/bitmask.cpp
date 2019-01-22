#include<bits/stdc++.h>

using namespace std;

/* a small bool array can be represented as a bitmask
 * 2^size - 1 full true
 * -= 2^i where i is the index where we wanna get false (example)
 *
 * basic binary operators
 *   & and
 *   | or
 *   ~ negation
 *   ^ exclusive or
 *
 * 1<<n == 2^n
 *
 * changing i to true
 *   m | (1<<i)
 * 
 * changing i to false
 *   m & ~((1<<i)):
 *
 *
 * smieszne zadanie na grafy z maskami
 *   mamy zadanie ze na wierzcholkach sa klucze i sa klucze potrzebne zeby odblokowywac krawedzie
 *   i szukamy najkrotszej sciezki
 *   robimy "drzewo" mozliwosci zdobywania kluczy (kazdy klucz to 1 bit, warstwy sa oznaczone maskami bitowymi kluczy
 *   i maja odblokowane te zablokowane krawedzie /w sensie że wgl istnieją/
 *   idziemy se dijkstra i mamy zmienna aktualnej warstwy, jak wchodzimy na klucz to elo zmienia nam sie warstwa | (1<<i)
 *
 *
 * inne zadanko (krasnale)
 *   mamy graf zaleznosci (wyzszosci) krasnali
 *   kto wazniejszy, ten ma siedziec bardziej z lewej
 *   i chcemy wiedziec na ile mozliwosci mozna ich usadzic
 *  
 *   robimy se toposorta zmodyfikowanego
 *   robimy se tabelke masek kogo kto musi przepuscic
 *   odwiedzajac sasiada a wsm usuwajac siebie ustawiam mu maske | swoja maske | swoj numer
 *   zeszyt "Matematyka" cd
 *   
 *   lecinmy dynamikiem od lewej
 *   dp[pos][mask] maska reprezentuje tych co siedza
 *   dp[1][0] = tyle ile jest korzeni w grafie zaleznosci (krasnali niezaleznych)
 *   
 *   dla kazdej pozycji dla kazdego rozw od maski
 *     lecimy po wsyzsktich krasnalach
 *       sprawdzamy czy maska krasnala zawiera sie w obecnej
 *         jak tak, to git i rozgalezia nam sie rekurencyjnie solv
 *
 * zawieranie sie masek (if a in b) <=> for each i if b[i]==1 yield a[i]
 * najlatwiej m | c == m
 */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
