#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+7;
int distances[N];
struct edge {
    int v, weight;
    edge (int _v, int _weight){
        v = _v; weight = _weight;
    }
};

vector<edge> G[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--){
        int a,b,w;
        cin >> a >> b >> w;
        G[a].push_back(edge(b,w));
        G[b].push_back(edge(a,w));
    }
    fill(distances, &(distances[N]), INT_MAX);
    distances[1] = 0;

    priority_queue<pair<int,int>> q;
    q.push({-0,1});
    while (!q.empty()){
        int t = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (t > distances[v]) continue;
        for (edge e : G[v]){
            if (distances[e.v] > t + e.weight ){
                distances[e.v] = t + e.weight;
                q.push({-distances[e.v], e.v});
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (distances[i] != INT_MAX){
            cout << distances[i] << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
