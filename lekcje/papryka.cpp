#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	uint32_t hi = 0, k = 0, a = 0, pw = 1;

	cin >> k;
	for (uint32_t i = 0; i <= k; i++){
		cin >> a;
		if (hi + 1 < pw){
			cout << hi + 1 << '\n';
			return 0;
		}
		hi += pw*a;

		pw *= 2;
	}
	cout << hi + 1 << '\n';
	return 0;
}