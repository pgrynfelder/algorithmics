#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
pair<int,int> xd = {INT_MAX, INT_MAX};

bool compare(pair<int, int> a, pair<int, int> b){
	a.first -= xd.first; a.second -= xd.second;
	b.first -= xd.first; b.second -= xd.second;
	return a.first * b.second - a.second * b.first > 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		pair<int, int> p;
		cin >> p.first >> p.second;
		if (p < xd){
			xd = p;
		}
		v.push_back(p);
	}
	sort(v.begin(), v.end(), compare);
	cout << xd.first << ' ' << xd.second << '\n';
	for (auto c : v){
		if (c != xd){
			cout << c.first << ' ' << c.second << '\n';
		}
	}
	return 0;
}
