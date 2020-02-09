#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int N = 1e5+7;
constexpr ll inf = 1e16;
int n, m;

ll dist[N];
struct edge {
    int v = 0, w = 0;
    edge (int _v, int _w){
        v = _v; w = _w;
    }
};

vector<edge> G[N];

void dijkstra(int x){
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    dist[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.emplace(0,x);
    while (!Q.empty()){
        int d = Q.top().first, v = Q.top().second;
        Q.pop();

        if (d > dist[v]) continue;

        for (edge e : G[v]){
            if (dist[e.v] > dist[v] + e.w){
                dist[e.v] = dist[v] + e.w;
                Q.emplace(dist[e.v], e.v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[b].emplace_back(a, w);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++){
        if (dist[i] >= inf){
            cout << "+oo\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
    vector<int> t = {3, 2, 1};
    sort(t.begin(), t.end(), [&](const int a, const int b){return a < b;});
    return 0;
}
