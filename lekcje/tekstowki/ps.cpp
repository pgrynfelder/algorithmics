#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
int ps[2*N];
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	s = "#" + a + "$" + b;
	ps[1] = 0; ps[0] = -1;
	for (int i = 2; i < s.size(); i++){
		ps[i] = ps[i-1];
		while (ps[i] >= 0 and s[i] != s[ps[i]+1]){
			ps[i] = ps[ps[i]];
		}
		ps[i]++;
	}
	vector<int> res;
	for (int i = a.size() + 1; i < s.size(); i++){
		if (ps[i] == a.size()){
			res.push_back(i - 2*a.size());
		}
	}

/*	for (int i = 0; i < s.size(); i++){
		cout << ps[i] << " ";
	}
	cout << "\n";
*/	cout << res.size() << "\n";
	for (int c : res){
		cout << c << " ";
	}
	return 0;
}
/*

abc
aabcabbabacaabcabcabcabcaabc

*/
