#include<bits/stdc++.h>

using namespace std;

bitset<300007> visited;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t n, m, l;
	cin >> n >> m;
	l = n;
	for (uint32_t i = 0; i < m; i++){
		uint32_t a;
		cin >> a;
		if(!visited[a] and a <= n){
			visited[a] = 1;
			l--;
			if (l == 0){
				cout << i + 1 << '\n';
				return 0;
			}
		}
	}
	cout << "-1 \n";
	return 0;
}