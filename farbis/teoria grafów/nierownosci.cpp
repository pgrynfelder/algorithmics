#include<bits/stdc++.h>
using namespace std;
int n, m;
constexpr int N = 2e5 + 7;
constexpr long long inf = 1e17 + 7;
vector<pair<int, int>> G[N];
long long dist[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
    }
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.emplace(0, 0);
    while (!q.empty()){
        int v = q.top().second;
        long long d = q.top().first;
        q.pop();

        if (d != dist[v]) continue;

        for (auto &e : G[v]){
            if (dist[e.first] > dist[v] + e.second){
                dist[e.first] = dist[v] + e.second;
                q.emplace(dist[e.first], e.first);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (dist[i] == inf){
            cout << "NIE\n";
            return 0;
        }
    }
    cout << "TAK\n";
    for (int i = 0; i <= n; i++){
        cout << dist[i] << " ";
    }
    return 0;
}

/*
3 5
0 1 1
1 3 2
2 1 1 
3 0 2 
3 2 3 
*/