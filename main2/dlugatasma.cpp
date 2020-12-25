#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	uint32_t n;
	double low = 1e9;
	cin >> n;
	for (uint32_t i = 0; i < n; i++){
		double a;
		cin >> a;
		low = min(low, a);
	}
	cout << fixed << setprecision(2) << low << '\n';
	return 0;
}