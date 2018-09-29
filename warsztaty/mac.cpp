#include<bits/stdc++.h>

using namespace std;

bool G[1007][1007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int u, v;
		cin >> v >> u;
		G[v][u] = G[u][v] = true;
	}

	cin >> q;
	for (int i = 0; i < q; i++){
		int v, u;
		cin >> v >> u;
		if (G[v][u]){
			cout << "TAK\n";
		} else {
			cout << "NIE\n";
		}
	}
	return 0;
}