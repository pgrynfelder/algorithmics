#include<bits/stdc++.h>
#define ai (i << 1)
#define bi (i << 1) + 1
using namespace std;

constexpr int N = 1e5 + 7;
vector<int> G[N];
int dist[N], visited[N], U[N];
int n,m,q;


void dfs(int v){
    for (int u : G[v]){
        if (!U[u]){
            U[u] = U[v];
            dfs(u);
        }
    }
}
    

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (!U[i]){
            U[i] = i;
            dfs(i);
        }
    }
    
    for (int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        if (a == b){
            cout << "0\n";
            continue;
        }
        if (U[a] != U[b]){
            cout << "-1\n";
            continue;
        }
        queue<int> Q;
        Q.push(a); Q.push(b);
        visited[a] = ai;
        dist[a] = dist[b] = 0;
        visited[b] = bi;
        bool running = true;
        while (running){
            int v = Q.front(); Q.pop();
            for (int u : G[v]){
                if ((visited[u] == bi and visited[v] == ai) or (visited[u] == ai and visited[v] == bi)){
                    running = false;
                    cout << dist[u] + dist[v] + 1 << "\n";
                    break;
                }
                if (visited[u] != visited[v]){
                    visited[u] = visited[v];
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
            }
        }
    }
    return 0;
}
    
