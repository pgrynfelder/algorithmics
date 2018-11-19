#include<bits/stdc++.h>

using namespace std;

uint32_t byreference(uint32_t &b){
	cout << &b << ' ' << b << '\n';
}
uint32_t bypointer(uint32_t *p){
	cout << p << ' ' << *p << '\n';
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t a;
	cout << &a << ' ' << a << '\n';
	a = 7;
	cout << &a << ' ' << a << '\n';
	
	uint32_t *p = &a;
	cout << p << ' ' << *p  << '\n';
	
	bypointer(&a);
	byreference(a);

	cout << "\nnow it's time for tables\n\n";

	uint32_t *t, **t2;

	t = new uint32_t[7];
       	*(t+3) = 7;
	t[5] = 9;
	for (uint32_t i = 0; i < 7; i++){
		cout << *(t + i) << ' ';
	}
	cout << '\n';
	
	t2 = new uint32_t*[8];
	
	for (uint32_t i = 0; i < 8; i++){
		*(t2+i) = new uint32_t[9];
	}

	*(*(t2+3)+5) = 7;
	for (uint32_t i = 0; i < 8; i++){
		for (uint32_t j = 0; j < 9; j++){
			cout << *(*(t2+i)+j) << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

void xd(){
	uint32_t **w, *t; // dynamically allocated tables, w[][], t[]
	int i = 0, n = 0, k = 0;
	//*(t+i) // equiv t[i]
	//*(*(w+n)+k) // equiv w[n][k]
}

