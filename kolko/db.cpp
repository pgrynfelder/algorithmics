#include<bits/stdc++.h>

using namespace std;

unordered_map<int32_t, int32_t> base;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int32_t n, a, b, c;
	cin >> n;
	for (int32_t i = 0; i < n; i++){
		cin >> a >> b;
		c = base[a] + b;
		if (c < 0){
			cout << "NIE\n";
		}
		else {
			cout << c << "\n";
			base[a] = c;
		}
	}
	return 0;
}
