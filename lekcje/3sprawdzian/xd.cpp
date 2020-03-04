#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7;
const long long INF = 1e18 + 7;

vector<pair<int, int>> graph[MAXN];
long long dist[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		
		graph[u].emplace_back(make_pair(v, w));
	}
	
	for(int i = 1; i <= n; ++i) {
		dist[i] = INF;
	}
	
	priority_queue<pair<long long, int>> q;
	q.push(make_pair(0, 0));
	while(!q.empty()) {
		int u = q.top().second;
		long long d = -q.top().first;
		q.pop();
		
		if(d == dist[u]) {
			for(pair<int, int> v: graph[u]) {
				if(d + v.second < dist[v.first]) {
					dist[v.first] = d + v.second;
					q.push(make_pair(-dist[v.first], v.first));
				}
			}
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		if(dist[i] == INF) {
			cout << "NIE";
			
			return 0;
		}
	}
	
	cout << "TAK\n";
	for(int i = 0; i <= n; ++i) {
		cout << dist[i] << ' ';
	}
	
	return 0;
}



