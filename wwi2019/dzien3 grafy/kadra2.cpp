#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5e5 + 7, MAXN = 1e6 + 7;
int fau[MAXN];
bool used[MAXN];
struct edge {
	int w, u, v;
} edges[MAXM];

int Find(const int &u) {
	if(fau[u] == u) {
		return u;
	}
	fau[u] = Find(fau[u]);
	return fau[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n = 0, m, u, v, w;
	long long res = 0;
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> w >> u >> v;
		edges[i] = {w, u, v};
		res += w;
		n = max(n, max(u, v));
	}
	
	for(int i = 1; i <= n; ++i) {
		fau[i] = i;
	}
	sort(edges + 1, edges + 1 + m,
	[&](const edge e0, const edge e1) {
		return e0.w > e1.w;
	});
	
	for(int i = 1; i <= m; ++i) {
		u = Find(edges[i].u);
		v = Find(edges[i].v);
		if(u == v) {
			if(!used[u]) {
				used[u] = 1;
				res -= edges[i].w;
			}
		}
		else if(!used[u] && !used[v]) {
			fau[u] = v;
			res -= edges[i].w;
		}
		else if(!(used[u] && used[v])) {
			fau[u] = v;
			used[v] = 1;
			res -= edges[i].w;
		}
	}
	cout << res;
	
    return 0;
}