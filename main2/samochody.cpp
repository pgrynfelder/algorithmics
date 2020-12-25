#include<bits/stdc++.h>

using namespace std;

vector<uint32_t> cars;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	uint32_t n, he = 0, hw = 0;
	uint64_t result = 0;
	cin >> n;

	for (uint32_t i = 0; i < n; i++){
		uint32_t a;
		cin >> a;
		cars.push_back(a);
		if (a == 1){
			hw++;
		}
	}
	for (uint32_t a : cars){
		if (a == 0){
			result += hw;
		} else {
			hw--;
		}
	}
	cout << result << "\n";
	return 0;
}