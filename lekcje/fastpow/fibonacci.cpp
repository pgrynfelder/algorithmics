#include<bits/stdc++.h>

using namespace std;
/*
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2)
 * 
 * rekurencje liniowe mozemy reprezentowac macierzami
 * 
 * zdefiniujmy ciag fibonnaciego mnozeniem maciezy
 * 
 * |a b|   |F(n-1)|   |F(n)  |   |a*F(n-1) + b*F(n-2)|
 * |c d| * |F(n-2)| = |F(n-1)| = |c*F(n-1) + d*F(n-2)| tak wiec a=1, b=1, c=1, d=0;
 * 
 * 									   |1 1|
 * to w sumie mozemy potegowac macierz |1 0|
 */
typedef long long ll;
int mod = 123456789;
struct m {
	ll tab[2][2];
	m(ll a1, ll a2, ll b1, ll b2){
		tab[0][0] = a1;
		tab[1][0] = a2;
		tab[0][1] = b1;
		tab[1][1] = b2;
	}
	m operator* (m b){
		return m((this->tab[0][0]*b.tab[0][0] + this->tab[1][0]*b.tab[0][1])%mod, 
		(this->tab[0][0]*b.tab[1][0] + this->tab[1][0]*b.tab[1][1])%mod, 
		(this->tab[0][1]*b.tab[0][0] + this->tab[1][1]*b.tab[0][1])%mod, 
		(this->tab[0][1]*b.tab[1][0] + this->tab[1][1]*b.tab[1][1])%mod);
	}
};

m power(m a, ll n){
	m r = m(1, 0, 0, 1);
	while (n > 0){
		if (n & 1){
			r = r*a;
		}
		a = a * a;
		n /= 2;
	}
	return r;
}

/*m powern(m a, ll n){
	m r = a;
	while (n > 1){
		r = r * a;
	}
	return r;
}*/

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	m a = m(1,1,1,0);
	m b = power(a, n-2);
	/*for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			cout << b.tab[j][i] << " ";
		}
	}*/
	cout << (b.tab[0][0] + b.tab[1][0])%mod << "\n";
	return 0;
}
