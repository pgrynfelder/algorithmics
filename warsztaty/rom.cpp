#include<bits/stdc++.h>

using namespace std;

bool visited[1000007];
vector<int> g[1000007];

void dfs(int v){
	if (visited[v]) return;
	visited[v] = true;

	for (int u : g[v]){
		if (!visited[u]) dfs(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[u].push_back(v);
	}

	dfs(1);

	for (int i = 1; i <= n; i++){
		if (visited[i]) cout << "TAK\n";
		else cout << "NIE\n";
	}
}