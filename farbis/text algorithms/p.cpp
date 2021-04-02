#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
string s;
int ps[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a;
	cin >> a;
	s = "#" + a;
	ps[1] = 0; ps[0] = -1;
	for (int i = 2; i < s.size(); i++){
		ps[i] = ps[i-1];
		while (ps[i] >= 0 and s[i] != s[ps[i]+1]){
			ps[i] = ps[ps[i]];
		}
		ps[i]++;
	}

	for (int i = 1; i < s.size(); i++){
		cout << ps[i] << " ";
	}
	cout << "\n";

	return 0;
}
/*
aabcabbacaabcacabcaabc
*/
