/*

bellman-ford
finds shortes path in graph with negative edges in O(nm)

*/

#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e3 + 7, M = 1e4 + 7;
constexpr long long inf = 1e12+7;
int n,m,q;

struct edge {
    int u = 0, v = 0, w = 0;
    edge (int _u, int _v, double _w){
        u = _u, v = _v, w = _w;
    }
};
vector<edge> E;
long long dist[N];
int p[N];

void bf(int s){
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
        p[i] = 0;
    }
    dist[s] = 0;
    for (int i = 1; i < n; i++){
        for (edge e : E){
            if (dist[e.v] > dist[e.u] + e.w and dist[e.u] < inf){
                dist[e.v] = dist[e.u] + e.w;
                p[e.v] = e.u;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.emplace_back(a, b, w);
    }
    while (q--){
        int u, v;
        cin >> u >> v;
        bf(u);
        if (dist[v] < inf){
            cout << dist[v] << " ";
            stack<int> res;
            while (v != 0){
                res.push(v);
                v = p[v];
            }
            cout << res.size() << " ";
            while (!res.empty()){
                cout << res.top() << " "; 
                res.pop();
            }
            cout << "\n";
        }
        else {
            cout << "NIE\n";
        }
    }
    return 0;
    
}
        
    
