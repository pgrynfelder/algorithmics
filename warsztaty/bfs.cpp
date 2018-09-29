#include<bits/stdc++.h>

using namespace std;

vector<int> g[1000007]; // table of vectors representing Graph

bool queued[1000007];
int dist[1000007];
queue<int> q;

void bfs(){
	dist[1] = 0;
	queued[1] = true;
	q.push(1);
	while (q.size() > 0){
		int v = q.front();
		q.pop();
		for (int u : g[v]){
			if (queued[u] == false){
				q.push(u);
				queued[u] = true;
				dist[u] = dist[v] + 1;
			}
		}
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
	bfs();
	for (int i = 1; i <= n; i++){
		if (visited[i]) cout << i << " ";
	}
	return 0;
}

/* alternative graph representation for small graphs, dijkstra etc
 *
 * bool / int g[n+1][n+1];
 */
