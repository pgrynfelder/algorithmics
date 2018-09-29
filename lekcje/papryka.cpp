#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	uint32_t hi = 0;
	uint32_t k, a, current;

	cin >> k;
	for (uint32_t i = 0; i < k; i++){
		cin >> a;
		current = 1;
		for (uint32_t j = 0;j < i; j++){
			current *= 2;
		}
		current *= a;
		if (hi > current + 1){
			continue;
		}
		else {
			cout << "";
		}	
	}
}