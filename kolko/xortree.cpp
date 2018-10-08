#include<bits/stdc++.h>

using namespace std;


uint32_t T[10000007];
uint32_t size = 1;

void change(uint32_t i, uint32_t n){
	i += size/2;
	T[i] = n;
	i /= 2;
	while (i > 0){
		T[i] = T[i*2] ^ T[i*2+1];
		i /= 2;
	}
}

uint32_t read(uint32_t a, uint32_t b, uint32_t l, uint32_t r, uint32_t i){
	if (a > r or b < l) {
		return 0;
	}
	else if (a <= l and b >= r){
		return T[i];
	}
	else {
		return read(a, b, l, (l+r)/2, i*2) ^ read(a, b, (l+r)/2+1, r, i*2+1);
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t n, m;

	cin >> n >> m;
	while (size < n){
		size *= 2;
	}
	size *= 2;
	for (uint32_t i = 0; i < n; i++){
		uint32_t a;
		cin >> a;
		change(i, a);
	}

	for (uint32_t i = 0; i < m; i++){
		uint32_t a, b;
		string word;
		
		cin >> word >> a >> b;
		if (word == "zamien"){
			uint32_t olda = T[size / 2 + a - 1];
			uint32_t oldb = T[size / 2 + b - 1];
			change(a - 1, oldb);
			change(b - 1, olda);
		}
		else if (word == "czytaj"){
			cout << read(a-1, b-1, 0, size/2 - 1, 1) << "\n";
		}
	}
	
	/*for (uint32_t i = 1; i < size; i*=2){
		for (uint32_t j = i; j < i*2; j++){
			cout << T[j] << ' ';
		}
		cout << "\n";
	}*/
	return 0;
}
