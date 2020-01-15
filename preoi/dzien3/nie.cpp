#include<bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
int n, m, q;

vector<int> G1[N];
vector<int> G2[N];

vector<int> sorted;
int visited[N];
int spojna[N];


void dfs(int v){
	for (int u : G1[v]){
		if (visited[u] != 1){
			visited[u] = 1;
			dfs(u);
		}
	}
	sorted.push_back(v);
}	

void dfs2(int v, int p){
	spojna[v] = spojna[p];
	for (int u : G2[v]){
		if (visited[u] != 2){
			visited[u] = 2;
			dfs2(u, v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		G1[b].push_back(a);
		G2[a].push_back(b);
	}
	
	for (int v = 1; v <= n; v++){
		if(visited[v] != 1){
			visited[v] = 1;
			dfs(v);
		}
	}
	
	// for (int a : sorted) cout << a << " ";
	for (int i = sorted.size()-1; i >= 0; i--){
		int v = sorted[i];
		if (spojna[v] == 0){
			spojna[v] = v;
			visited[v] = 2;
			dfs2(v, v);
		}
	} 

	cin >> q;
	while (q--){
		int a, b;
		cin >> a >> b;
		cout << (spojna[a] == spojna[b] ? "Tak\n" : "Nie\n");
	}
	return 0;
}
/*

3 4
1 2
2 2
2 1
2 3
3
1 2
1 3
2 3
*/
