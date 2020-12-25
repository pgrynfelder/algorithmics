#include<bits/stdc++.h>

using namespace std;

uint32_t C[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t n;
	cin >> n;
	for (uint32_t i = 0; i < n; i++){
		uint32_t a;
		cin >> a;
		if (a <= 1000000)
			C[a]+= 1;
	}
	for (uint32_t i = 1; i <= n; i++){
		if (C[i] != 1){
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	return 0;
}
