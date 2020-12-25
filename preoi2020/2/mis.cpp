#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+7, M = 1e6+7;
vector<int> G[N], G2[N];
int visited[N];
int U[N];
vector<int> sorted;
int n, m;

void dfs(int v){
    for (int u : G[v]){
        if (!visited[u]){
            visited[u] = 1;
            dfs(u);
        }
    }
    sorted.push_back(v);
}

void dfs2(int v){
    for (int u : G2[v]){
        if (visited[u] != 2){
            visited[u] = 2;
            U[u] = U[v];
            dfs2(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> m;
    cin.tie(0);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b); G2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            visited[i] = 1;
            dfs(i);
        }
    }
    reverse(sorted.begin(), sorted.end());
    for (int c : sorted){
        // cout << c << " ";
        if (U[c] == 0){
            visited[c] = 2;
            U[c] = c;
            dfs2(c);
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << U[i] << "\n";
    // }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << "MISJA " << ((U[a] == U[b]) ? "UDANA" : "NIEUDANA") << "\n";
    }
    return 0;
}
