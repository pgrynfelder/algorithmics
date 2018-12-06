#include<bits/stdc++.h>

using namespace std;

string t[1000007];

bool compare(const string &a, const string &b){
	int32_t cost_a = 0, cost_b = 0;
	cost_a = (a[0] - '0')*1000 + (a[3] - '0')*100 + (a[2] - '0')*10 + (a[1] - '0')*1;
	if (cost_a < 1000) cost_a = 1000;
	cost_b = (b[0] - '0')*1000 + (b[3] - '0')*100 + (b[2] - '0')*10 + (b[1] - '0')*1;
	if (cost_b < 1000) cost_b = 1000;
	return cost_a < cost_b;
	
}

	
	

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int32_t n;
	cin >> n;
	for (int32_t i = 0; i < n; i++){
		cin >> t[i];
	}
	sort(t, t+n, compare);
	for (int32_t i = 0; i < n; i++){
		cout << t[i] << ' ';
	}
	return 0;
}
