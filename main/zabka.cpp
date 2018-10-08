#include<bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a, b, c;	
	cin >> a >> b >> c;
	if ((b-a)%c==0) cout << (b-a)/c << "\n";
	else cout << (b-a)/c+1 << "\n";
	return 0;
}
