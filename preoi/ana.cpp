#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+7;
constexpr long long inf = 1e12;
struct edge {
    int a, b, d, i;
    bool flagged = false;
    edge(int _a, int _b, int _d, int _i){
        a = _a; b = _b; d = _d; i = _i;
    }
};
vector<edge> G[N], G2[N];//, E;
long long dist[N], dist2[N];
edge* parent_edge[N];
int n, m;

void dijkstra(){
    for (int i = 2; i <= n; i++){
        dist[i] = inf;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0,1});
    while (!Q.empty()){
        int d = Q.top().first; int a = Q.top().second;
        Q.pop();
        if (d > dist[a]) continue;
        for (auto &e : G[a]){
            if (e.d + dist[a] < dist[e.b]){
                parent_edge[e.b] = &e;
                dist[e.b] = e.d + dist[a];
                Q.push({dist[e.b], e.b});
            }
        }
    }
}
void dijkstra2(){
    for (int i = 1; i < n; i++){
        dist2[i] = inf;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0,n});
    while (!Q.empty()){
        int d = Q.top().first; int a = Q.top().second;
        Q.pop();
        if (d > dist2[a]) continue;
        for (auto &e : G2[a]){
            if (e.d + dist2[a] < dist2[e.b]){
                dist2[e.b] = e.d + dist2[a];
                Q.push({dist2[e.b], e.b});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({a, b, c, i});
        G2[b].push_back({b, a, c, i});
        // E.push_back({a, b, c, i});
    }
    dijkstra();
    int v = n;
    while (parent_edge[v]){
        // cout << v << "<-";
        parent_edge[v] -> flagged = true;
        v = parent_edge[v] -> a;
    }
    dijkstra2(); 
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << dist[i] << " " << dist2[i] << "\n";
    // }
    long long res = inf;
    for (int i = 1; i <= n; i++){
        for (auto &e : G[i]){
            if (!e.flagged){
                res = min(res, dist[e.a] + dist2[e.b] + e.d);
            }
        }
    }
    if (res < inf){
        cout << res << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
