#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+7;
vector<int> G[N];
int n, m, q;

int U[N];

void dfs(int v){
    for (int u : G[v]){
        if (U[u] == 0){
            U[u] = U[v];
            dfs(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (U[i] == 0){
            U[i] = i;
            dfs(i);
        }
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << ((U[a] == U[b]) ? "T\n" : "N\n");
    }
    return 0;
}
