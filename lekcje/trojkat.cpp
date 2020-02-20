#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+7, inf = 1e6 + 7;
vector<int> G[N];
int dist[N];
int deg[N];
int n, m;

bool bfs(int s){
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    int siz = 1;
    while (!Q.empty()){
        int v = Q.front(); Q.pop();
        for (int u : G[v]){
            if (dist[u] == inf){
                dist[u] = dist[v] + 1;
                if (dist[u] == 2){
                    cout << "TAK\n";
                    cout << s << " " << v << " " << u << "\n";
                    return true;
                }
                siz++;
                Q.push(u);
            }
        }
    }

    stack<int> res;
    for (int u : G[s]){
        if (deg[u] < siz - 1){
            res.push(u);
        }
        if (res.size() > 1){
            cout << "TAK\n";
            cout << res.top() << " "; res.pop();
            cout << s << " ";
            cout << res.top() << "\n";
            return true;
        }
    }
    return false;
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++; deg[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (dist[i] == inf){
            if (bfs(i)){
                return 0;
            }
        }
    }
    cout << "NIE\n";
    return 0;
}
