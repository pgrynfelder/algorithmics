#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7;

struct edge {
	int v = 0, w = 0;
	edge(int _v, int _w){
		v = _v; w = _w;
		//cout << "Created edge to " << v << " with weight " << w << "\n";
	}
};

vector<edge> G[N];

int fu[N];
long long fsize[N];

int f(int a){
	if (fu[a] == a) return a;
	fu[a] = f(fu[a]);
	return fu[a];
}
void u(int a, int b){
	//cout << "union " << a << " " << b << "\n";
	a = f(a); b = f(b);
	if (a == b) return;
	if (fsize[a] > fsize[b]) swap(a, b);
	fu[a] = b;
	fsize[b] += fsize[a];
}

int n, m, x;
long long result;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		if (w <= x){
			G[u].push_back(edge(v, w));
			G[v].push_back(edge(u, w));
		}
	}
	for (int i = 1; i <= n; i++){
		fu[i] = i;
		fsize[i] = 1;
	}
	for (int v = 1; v <= n; v++){
		for (edge e : G[v]){
			if (e.w <= x and f(v) != f(e.v)){
				result += fsize[f(v)] * fsize[f(e.v)];
				u(v, e.v);
			}
		}
	}
	
	for (int i = 1; i <= n; i++){
		fu[i] = i;
		fsize[i] = 1;
	}
	for (int v = 1; v <= n; v++){
		for (edge e : G[v]){
			if (e.w < x and f(v) != f(e.v)){
				result -= fsize[f(v)] * fsize[f(e.v)];
				u(v, e.v);
			}
		}
	}
	cout << result << "\n";
	return 0;
}
/*
7 6 3
1 2 1
1 3 2
3 4 3
4 5 1
4 6 2
1 7 4

8 8 4
1 3 2
2 4 1
1 5 1
6 7 3
5 8 4
8 4 4
6 5 5
7 8 6

*/
