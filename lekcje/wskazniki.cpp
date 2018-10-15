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
	cout << p << ' ' << a << '\n';

	bypointer(&a);
	byreference(a);
	return 0;
}

void xd(){
	uint32_t **w, *t; // dynamically allocated tables, w[][], t[]
	int i = 0, n = 0, k = 0;
	//*(t+i) // equiv t[i]
	//*((w+n)*k) // equiv w[n][k]
}

