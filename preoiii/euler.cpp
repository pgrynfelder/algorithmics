/* euler path, euler circuit, euler cycle */
#include<bits/stdc++.h>
using namespace std;

constexpr int M = 2.5e5 + 7, N = 1e5 + 7;
int n, m;
struct edge {
    int v = 0, i = 0;
    edge (int _v, int _i){
        v = _v; i = _i;
    }
};
bool visitedE[M];
stack<int> res;
vector<edge> G[N];
bool visitedV[N];
int deg[N];

void euler(int v){
    for (edge &e : G[v]){
        if (!visitedE[e.i]){
            visitedE[e.i] = 1;
            visitedV[e.v] = 1;
            euler(e.v);
        }
    }
    res.push(v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++; deg[b]++;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    bool made_euler = false;
    for (int i = 1; i <= n; i++){
        if (deg[i] & 1){
            cout << "NIE\n";
            return 0;
        }
        if (deg[i] and !made_euler){
            visitedV[i] = 1;
            euler(i);
            made_euler = 1;
        }
        else if (deg[i] and made_euler and !visitedV[i]){
            cout << "NIE\n";
            return 0;
        }
    }
    cout << "TAK\n";
    while (res.size() > 1){
        cout << res.top() << " "; res.pop();
    }
}
