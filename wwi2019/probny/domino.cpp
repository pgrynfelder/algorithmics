#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int bfs(vector<vector<int>> &G, vector<bool> &V, int s){
	int result = 0;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		if (V[v]){
			continue;
		}
		result++;
		V[v] = true;
		for (auto u : G[v]){
			Q.push(u);
		}
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, l, result = 0;
	cin >> n >> m >> l;
	
	vector<vector<int>> G(n+1);
	vector<bool> V(n+1, false);
	while (m-->0){
		int x,y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	while (l-->0){
		int s;
		cin >> s;
		result += bfs(G, V, s);
	}
	cout << result << '\n';
	return 0;
}
