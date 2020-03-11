#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
constexpr ull N = 2e5 +7, k = 31, M = 2147483647;

ull p[N] = {1, 107};

ull mod(ull x){
	x = (x >> k) + (x & M);
	x = (x >> k) + (x & M);
	return x == M ? 0 : x;
}
string s;
ull t[N];
int n;

ull geth(int i, int j){
	return mod(M + t[j] - mod(t[i-1]*p[j-i+1])); 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;	
	n = s.size();
	for (int i = 2; i <= n; i++){
		p[i] = mod(p[i-1] * p[1]);
	}
	for (int i = 0; i < s.size(); i++){
		t[i+1] = mod(t[i] * p[1] + s[i]);
	}

	int q;
	cin >> q;
	while (q--){
		int a, b, l;
		cin >> a >> b >> l;
		if (geth(a, a+l-1) == geth(b, b+l-1)){
			cout << "TAK\n";
		}
		else {
			cout << "NIE\n";
		}
	}
//	cout << M;
	return 0;
}

/*
ababbabbaaabbbabba
3
1 3 2
3 15 4
3 14 5
*/
