#include<bits/stdc++.h>
using namespace std;

constexpr long long inf = 1e18, mininf = 1e17;

struct edge {
	int u=0, v=0, c=0;
	edge(int _u, int _v, int _c){
		u = _u; v = _v; c = _c;
	}
	edge(){}
};
vector<edge> E;
vector<long long> d;
vector<int> p;

int n, m, q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	E.resize(m);
	d.resize(n+1);
	p.resize(n+1);
	
	for (int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		E[i] = {u, v, c};
	}
	while (q--){
		fill(d.begin(), d.end()-1, +inf);
		fill(p.begin(), p.end()-1, -1);
		int a, b;
		cin >> a >> b;
		p[a] = a;
		d[a] = 0;	
		for (int i = 1; i < n; i++){
			for (edge e : E){
				if (d[e.u] + e.c < d[e.v]){
					d[e.v] = d[e.u] + e.c;
					p[e.v] = e.u;
				}
			}
		}
		if (d[b] > mininf){
			cout << "NIE\n";
		}
		else {
			vector<int> res;
			cout << d[b] << " ";
			while(p[b] != b){
				res.push_back(b);
				b = p[b];
			}
			cout << res.size() << " ";
			for (auto xd : res){
				cout << xd << " ";
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
