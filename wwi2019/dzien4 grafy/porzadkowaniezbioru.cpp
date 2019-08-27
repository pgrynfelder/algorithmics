#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> degin;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> sorted;
    int n, m;
    cin >> n >> m;

    G.resize(n+1);
    degin.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        degin[v]++;
    }

    queue<int> q;

    for (int i = 1; i < degin.size(); i++){
        if (degin[i] == 0){
            q.push(i);
        }
    }
    
    while (!q.empty()){
        if (q.size() > 1){
            cout << "NIE\n";
            return 0;
        }
        int u = q.front();
        q.pop();
        sorted.push_back(u);
        for (int v : G[u]){
            degin[v]--;
            if (degin[v]==0) q.push(v);
        }
    }
    if (sorted.size() < n){
        cout << "NIE\n";
        return 0;
    }

    cout << "TAK\n";
    for (int u : sorted){
        cout << u << ' ';
    }

    return 0;
}
