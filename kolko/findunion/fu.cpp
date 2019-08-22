#include<bits/stdc++.h>

using namespace std;

int FU[x]; // table of representatives

int f(int x){
	if (FU[x] == x){
		return x;
	}
	FU[x] = f(FU[x]);
	return FU[x];
}

void u(int x, int y){
	int a = f(x), b = f(y);
	FU[b] = a;
}

/* 
 * jak mamy zadanko na usuwanie krawedzi to dobrze wklepac te co zawsze sa i dodawac te co mialyby byc odjete i robic fu
 */

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
