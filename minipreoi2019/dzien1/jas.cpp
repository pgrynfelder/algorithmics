#include<bits/stdc++.h>
using namespace std;
/* Stachuuuu! Co? */

int a, m, d;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> m >> d;
	bool reversed = false;
	if (d > m){
		reversed = true;
		a *= -1; m *= -1; d *= -1;
	}
	long long x = 11*a - 4*d - 6*m - 10;
	long long seq[] = {d, d, d, d, m, m, m + 1, m + 2, m + 3, m + 4, x};
	cout << 11 << "\n";
	for (int y : seq){
		cout << ((reversed) ? -y : y) << " ";
	}
	return 0;	
}
