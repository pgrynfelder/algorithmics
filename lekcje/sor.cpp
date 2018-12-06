#include<bits/stdc++.h>

using namespace std;

bool compare(const string &a, const string &b){
	if (a.size() == b.size()){
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

string t[1000];

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
		cout << t[i] << '\n';
	}

	return 0;
}
