#include<bits/stdc++.h>
using namespace std;

constexpr long long P = 1e6 + 7, M = 1e9 + 321;
constexpr int N = 57;

int n, q, m;


int pow(long long a, int p){
	if (p = 0) return 1;
	if (p & 1) return pow(a, p-1)*a % M;
	long long res = pow(a, p-1);
	return res * res % M;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		// hash pointer tree
	}
	return 0;
}


/*

4 5
aaccx
aabwd
abccd
abbwx
3
1 4 1 2
3 4 2 4
3 4 2 4

*/
