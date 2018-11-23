#include<bits/stdc++.h>

using namespace std;

vector<int32_t> G[2000007];
bitset<2000007> visited;
vector<int32_t> s;
int32_t possibilities[2000007];

void dfs(int32_t v){
    if (visited[v]) return;
    visited[v] = true;
    for (int32_t w : G[v]){
        dfs(w);
    }
    s.push_back(v); // adding post order in order to toposort
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int32_t n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int32_t i = 0; i < m; i++){
        int32_t v, w;
        cin >> v >> w;
        G[v].push_back(w);
    }
    dfs(a); // no need for full topo sort
    possibilities[b] = 1;
    for (int32_t v : s){
        for (int32_t w : G[v]){
            possibilities[v] = (possibilities[v] + possibilities[w]) % (1000000000+9);
        }
    }
    cout << possibilities[a];
	return 0;
}