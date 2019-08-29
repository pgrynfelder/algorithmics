#include<bits/stdc++.h>
using namespace std;

struct edge {
    int v, weight;
    edge (int _v, int _weight){
        v = _v, weight = _weight;
    }
};

int n, m;
vector<vector<edge>> G;
vector<int> blades;
vector<bool> visited;

void dfs(int v, int endurance){
    for (auto e : G[v]){
        if (!visited[e.v] and endurance >= e.weight){
            visited[e.v] = true;
            dfs(e.v, max(endurance, blades[e.v]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    blades.resize(n+1);
    G.resize(n+1);
    visited.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> blades[i];
    }

    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    visited[1] = true;
    dfs(1, blades[1]);

    if (visited[n]){
        cout << "TAK\n";
    }
    else {
        cout << "NIE\n";    
    }
    return 0;
}
