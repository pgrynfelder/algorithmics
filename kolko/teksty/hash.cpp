#include<bits/stdc++.h>

using namespace std;
/* zmieniamy slowo na liczbe czy cos preferably long long
 * jezeli A != B, most probably hash(A) != hash(B)
 * hash("aa") = (i*base^1 + i*base^0) % prime
 * base should be relatively prime to the prime
 * example base: 997
 * example prime: 1e9+7
 * 
 * if huge time limits, the we can double-check with different prime etc.
 *
 * hashing next substring knowing previous i-1st
 * ((hash(i) - T[i] + M) % M) * P + T[i+n]
 *
 * substracting from hash
 * thus
 * prefix hashing
 *
 */
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
