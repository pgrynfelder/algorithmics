#include<bits/stdc++.h>

using namespace std;

T[2][3][1000007];

uint32_t unique(uint32_t a, b, i){
	uint32_t result = 0;
	uint32_t counts[4];
	for (uint32_t k = 0; k < 3; k++){
		counts[T[a][b][i-k]]++;
	}
	for (uint32_t k = 1; k < 4; k++){
		if (counts[k] != 0){
			result++;
		}
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
