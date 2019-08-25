#include<bits/stdc++.h>
using namespace std;

vector<int> degin;
vector<vector<int>> G;
vector<int> sorted;
vector<bool> visited;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    degin.resize(n+1);
    visited.resize(n+1);
    while (m--){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        degin[b]++;
    }
    for (auto &a : G){
        sort(a.begin(), a.end());
    }

    for (int i = 1; i <= n; i++){
        if (degin[i] == 0 and !visited[i]){
            queue<int> q;
            q.push(i);
            sorted.push_back(i);
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for (int u : G[v]){
                    degin[u]--;
                    if (degin[u] == 0){
                        q.push(u);
                        visited[u] = 1;
                        sorted.push_back(u);
                    }
                }
            }
        }
    } 
    if (sorted.size() == n){
        cout << "TAK\n";
        for (int v : sorted){
            cout << v << ' ';
        }
    }
    else {
        cout << "NIE\n";
    }
    return 0;
}
/*
5 4
2 4
2 1
1 4
4 3
*/