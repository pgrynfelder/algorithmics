#include<bits/stdc++.h>
using namespace std;

constexpr int N = 107, C = 1e4, inf = 1e9+7;
int n, m;
vector<pair<int, int>> G[N];
long long dist[N];

bool improve(int x){
    bool improved = 0;
    for (int v = 1; v <= n; v++){
        for (auto e : G[v]){
            if (dist[e.first] > dist[v] + e.second + x){
                dist[e.first] = dist[v] + e.second + x;
                improved = true;
            }
        }
    }
    return improved;
}

bool bellman_ford(int v, int x){
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    dist[v] = 0;
    for (int i = 1; i < n; i++){
        if (!improve(x)){
            return false; // x too big, surely no negative cycles
        }
    }
    return improve(x); // if improved, there's negative cycle
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b, c* -C); // gonna find smallest
    }
    int l = -1e9, r = 1e9;
    while (l < r){
        int mid = (l+r)/2;
        if (bellman_ford(1, mid)){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << (double)l/C << "\n";    
    return 0;
}
