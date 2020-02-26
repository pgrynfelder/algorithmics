#include<bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
int n, m;
struct edge {
    int v = 0, i = 0, u = 0;
    edge (int _u, int _v, int _i){
        u = _u; v = _v; i = _i;
    }
};

vector<edge> G[N];
edge* p[N];
int layer[N];
int highest[N];

void dfs(int v){
    highest[v] = layer[v];
    for (edge &e : G[v]){
        if (!p[e.v]){
            p[e.v] = &e;
            layer[e.v] = layer[v] + 1;
            dfs(e.v);
        }
        if (e.i != p[v] -> i){
            highest[v] = min(highest[v], highest[e.v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(a, b, i);
        G[b].emplace_back(b, a, i);
    }
    p[1] = new edge(0, 1, 0);
    dfs(1);
    /*
    for (int i = 1; i <= n; i++){
        cout << highest[i] << " ";
    }
    */
    priority_queue<int, vector<int>, greater<int>> res;
    for (int v = 2; v <= n; v++){
        if (highest[v] >= layer[v]){
            res.push(p[v] -> i);
        }
    }
    cout << res.size() << "\n";
    while (!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
     
    return 0;
}

/*

5 5 
1  2
2  3
2  4
3  5
1  3


*/
