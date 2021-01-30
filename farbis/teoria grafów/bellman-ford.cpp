#include<bits/stdc++.h>
using namespace std;
// bellman-ford ford-bellman ford bellman
// shortest paths even if there are negative paths, can find negative cycle
constexpr long long inf = 1e18, mininf = 1e17;
constexpr int M = 1e4 + 7, N = 1e3 + 7;
struct edge {
	int u=0, v=0, c=0;
	edge(int _u, int _v, int _c){
		u = _u; v = _v; c = _c;
	}
	edge(){}
};
edge E[M];
long long d[N];
edge* p[N];

int n, m, q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	
	for (int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		E[i] = {u, v, c};
	}
	while (q--){
		for (int i = 1; i <= n; i++){
			d[i] = inf;
			p[i] = 0;
		}
		int a, b;
		cin >> a >> b;
		d[a] = 0;	
		for (int i = 1; i < n; i++){ // n-1 repetitions -> if can still be relaxed, there's negative cycle
			for (edge &e : E){
				if (d[e.u] + e.c < d[e.v]){
					d[e.v] = d[e.u] + e.c;
					p[e.v] = &e;
				}
			}
		}
		if (d[b] > mininf){
			cout << "NIE\n";
		}
		else {
			stack<int> res;
			cout << d[b] << " ";
			while (p[b]){
				res.push(b);
				b = p[b] -> u;
			}
			cout << res.size() << " ";
			while (!res.empty()){
				cout << res.top() << " ";
				res.pop();
			}
			cout << "\n";
		}
	}
	return 0;
}

/*

4 5 3
1 3 -2
1 2 1
3 2 3
2 4 -4
4 3 1
1 4
4 2
4 1

*/
