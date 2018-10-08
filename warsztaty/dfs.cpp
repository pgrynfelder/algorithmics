#include<bits/stdc++.h>

using namespace std;

vector<int> g[1000000]; // table of vectors representing Graph
bool visited[1000000];

void dfs(int v){ // O(n+m) depth-first search
	if (visited[v]) return;

	visited[v] = true;
	for(int u : g[v]){
		dfs(u);
	}
}

int main(){
	int n; // wierzcholki vertices
	int m; // krawedzie 
	
	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a); // only if bidirectional
	}
	dfs(1);
	for (int i = 1; i <= n; i++){
		if (visited[i]) cout << i << " ";
	}
	return 0;
}

/* alternative graph representation for small graphs, dijkstra etc
 *
 * bool / int g[n+1][n+1];
 */
