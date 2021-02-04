// wawszczak

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7, LOGN = 18;

vector<int> graph[MAXN];
int depth[MAXN], jump[MAXN][LOGN];
pair<int, int> max1[MAXN], max2[MAXN];

void dfs(int u) {
	for(int bit = 1; bit < LOGN; ++bit) {
		jump[u][bit] = jump[jump[u][bit - 1]][bit - 1];
	}
	
	for(int v: graph[u]) {
		if(v != jump[u][0]) {
			jump[v][0] = u;
			depth[v] = depth[u] + 1;
			dfs(v);
			if(max1[v].first + 1 > max1[u].first) {
				max2[u] = max1[u];
				max1[u] = make_pair(max1[v].first + 1, v);
			}
			else if(max1[v].first + 1 > max2[u].first) {
				max2[u] = make_pair(max1[v].first + 1, v);
			}
		}
	}
}

void dfs2(int u, int d) {
	for(int v: graph[u]) {
		if(v != jump[u][0]) {
			if(v == max1[u].second) {
				dfs2(v, max(d, max2[u].first) + 1);
			}
			else {
				dfs2(v, max(d, max1[u].first) + 1);
			}
		}
	}
	if(d > max1[u].first) {
		max2[u] = max1[u];
		max1[u] = make_pair(d, jump[u][0]);
	}
	else if(d > max2[u].first) {
		max2[u] = make_pair(d, jump[u][0]);
	}
}

int lca(int u, int v) {
	for(int bit = LOGN - 1; bit >= 0; --bit) {
		if(depth[jump[u][bit]] >= depth[v]) {
			u = jump[u][bit];
		}
		if(depth[jump[v][bit]] >= depth[u]) {
			v = jump[v][bit];
		}
	}
	
	if(u == v) {
		return u;
	}
	
	for(int bit = LOGN - 1; bit >= 0; --bit) {
		if(jump[u][bit] != jump[v][bit]) {
			u = jump[u][bit];
			v = jump[v][bit];
		}
	}
	return jump[u][0];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	
	jump[1][0] = 1;
	dfs(1);
	dfs2(1, 0);
	
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		
		if(u == v) {
			cout << 0 << '\n';
			continue;
		}
		
		int w = lca(u, v);
		int dist1 = depth[u] - depth[w], dist2 = depth[v] - depth[w];
		int up1 = (dist1 + dist2) / 2, up2 = (dist1 + dist2 - 1) / 2;
		int a = u, b = v;
		if(up1 > dist1) {
			a = v;
			up1 = dist1 + dist2 - up1;
		}
		if(up2 > dist2) {
			b = u;
			up2 = dist1 + dist2 - up2;
		}
		for(int bit = 0; bit < LOGN; ++bit) {
			if(up1 >> bit & 1) {
				a = jump[a][bit];
			}
			if(up2 >> bit & 1) {
				b = jump[b][bit];
			}
		}
		
		cout << dist(u, a) + (max1[b].second == a ? max2[b].first : max1[b].first) + 1 << '\n';
	}
	
	return 0;
}