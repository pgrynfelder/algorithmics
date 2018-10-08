#include<bits/stdc++.h>

using namespace std;
bool ip(string w){
	uint32_t n = w.size();
	for (uint32_t i = 0; i < n; i++){
		if (w[i] != w[n-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t i = 0;
	string w;
	while(cin >> w){
		if (ip(w)){
			cout << i << '\n';
		}
		i++;
	}
	return 0;
}
