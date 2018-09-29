#include<bits/stdc++.h>

using namespace std;

int dist[100007];
vector<int> G[100007];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		dist[i] = -1;
	}
	dist[1] = 0;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}

	Q.push(1);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (int u : G[v]){
			if (dist[u] == -1){
				dist[u] = dist[v] + 1;
				Q.push(u);
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		cout << dist[i] << "\n";
	}
	return 0;
}