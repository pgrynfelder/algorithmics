#include<bits/stdc++.h>

using namespace std;

vector<int> G[100007];
queue<int> Q;
int deg[100007];
bool qd[100007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int v, u;
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
		deg[v]++;
		deg[u]++;
	}
	for (int i = 1; i <= n; i++){
		if (deg[i] == 1) {
			Q.push(i);
			qd[i] = true;
		}
	}
	int v;
	while(!Q.empty()){
		v = Q.front();
		Q.pop();
		
		for (int u : G[v]){
			deg[u]--;
			if (deg[u] == 1 and !qd[u]){
				Q.push(u);
				qd[u] = true;
			}
		}
		
	}
	cout << v << "\n";
	return 0;

}
