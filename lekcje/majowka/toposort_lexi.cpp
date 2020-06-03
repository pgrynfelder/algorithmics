#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+7;
vector<int> G[N];
int in[N];
int n, m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        in[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> Q;
    vector<int> sorted;
    for (int u = 1; u <= n; u++){
        if (in[u] == 0){
            Q.emplace(u);
        }
    }
    while (!Q.empty()){
        int u = Q.top();
        Q.pop();
        sorted.emplace_back(u);
        for (int v : G[u]){
            in[v]--;
            if (in[v] == 0){
                Q.emplace(v);
            }
        }
    }
    for (int u = 1; u <= n; u++){
        if (in[u]){
            cout << "NIE\n";
            return 0;
        }
    }
    cout << "TAK\n";
    for (int u : sorted) cout << u << " ";
    return 0;
}
