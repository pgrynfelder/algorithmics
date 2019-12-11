#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;


vector<int> G[N];
int visited[N];
int parent[N];
int n, m, q;


void bfs(int v, int t, int iter){
    bool found = false;
    queue<int> q;
    parent[v] = -1;
    visited[v] = iter;
    q.push(v);
    while (!q.empty()){
        v = q.front(); q.pop();
        if (v == t){
            found = true;
            break;
        }
        for (int u : G[v]){
            if (visited[u] != iter){
                visited[u] = iter;
                parent[u] = v;
                q.push(u);
            }
        }
    }
    if (!found){
        cout << "-1\n"; return;
    }
    else {
        stack<int> s;
        while (v != -1){
            s.push(v);
            v = parent[v];

        }
        cout << s.size() - 1 << " ";
        while (!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
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
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        bfs(a, b, i);
    }

    return 0;
}
