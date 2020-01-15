#include<bits/stdc++.h>
using namespace std;

constexpr long long N = 1e12+7, M = 1e6+7, K = 1e3+7;
bool composite[M];

void sieve(){
	composite[0] = composite[1] = true;	
	for (int k = 2; k < K; k++){
		if (composite[k]) continue;
		int i = 2*k;
		while (i < M){
			composite[i] = true;
			i += k;
		}
	}
		
}
			
			

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	long long x;
	cin >> q;
	sieve();
	while (q--){
		cin >> x;
		long long root = sqrt((double)x);
		if (root * root != x){
			cout << "NIE\n"; continue;
		}
		cout << (composite[root] ? "NIE\n" : "TAK\n");
	}
		
	return 0;
}

