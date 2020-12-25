#include<bits/stdc++.h>

using namespace std;

uint32_t buttons[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	uint32_t n, m, desired = 0, hi = 0;
	cin >> n >> m;
	for (uint32_t i = 0; i < m; i++){
		uint32_t a;
		cin >> a;
		if (a == n+1){
			desired = hi;
		}
		else {
			if (buttons[a] < desired){
				buttons[a] = desired;
			}
			buttons[a]++;
			if (buttons[a] > hi){
				hi = buttons[a];
			}
		}
	}
	for (uint32_t i = 1; i <= n; i++){
		cout << max(desired, buttons[i]) << ' ';
	}
	return 0;
}