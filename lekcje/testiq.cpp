#include<bits/stdc++.h>
using namespace std;

vector<int> xd[1000007];

int lbs(vector<int> &v, int x, int l, int r){
	if (v.size() < 1 or x > v[v.size()-1]){
		return -1;
	}
	while (l < r){
		int mid = (l+r)/2;
		if (x <= v[mid]){
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n, p, a;
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> a;
		xd[a].push_back(i);
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p;
		int current = 0;
		for (int j = 0; j < p; j++){
			cin >> a;
			int x = lbs(xd[a], current, 0, xd[a].size()-1);
			if (x == -1){
				current = INT_MAX;
			}
			else {
				current = xd[a][x] + 1;
			}
		}
		cout << (current-1 <= m ? "TAK\n" : "NIE\n");
	}
	return 0;
}