#include<bits/stdc++.h>
using namespace std;

constexpr int N = 5e5+7, M = 1e6 + 7, LOGN = 20;
vector<int> G[N];
int p[N];
int dist[N];
int jptr[N][LOGN];
int mod[N];
int n, m;

void dfs(int v){
    for (int u : G[v]){
        if (u != p[v]){
            p[u] = v;
            dist[u] = dist[v] + 1;
            jptr[u][0] = v;
            for (int i = 1; i < LOGN; i++){
                jptr[u][i] = jptr[jptr[u][i-1]][i-1];
            }
            dfs(u);
        }
    }
}  

int child_on_path(int a, int b){ // a must be higher than b
    for (int i = LOGN - 1; i >= 0; i--){
        if (dist[jptr[b][i]] > dist[a]){
            b = jptr[b][i];
        }
    }
    return (p[b] == a ? b : -1);
}

vector<int> res;
void dfs2(int v, int state){
    state += mod[v];
    if (state <= 0){
        res.push_back(v);
    }
    for (int u : G[v]){
        if (u != p[v]){
            dfs2(u, state);
        }
    }
}


int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    // G[0].push_back(1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < LOGN; i++){
        jptr[1][i] = 1;
    }
    dfs(1);
    for (int i = n; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if (dist[a] > dist[b]){ // a is supposed to be higher
            swap(a, b);
        }
        int xd = child_on_path(a, b);
        if (xd == -1){
            mod[1] += 1;
            mod[a] -= 1;
            mod[b] -= 1;
        }
        else {
            mod[xd] += 1;
            mod[b] -= 1;
        }
    }
    dfs2(1, 0);
    if (res.empty()){
        cout << "NIE\n";
    }
    else {
        cout << "TAK\n";
        sort(res.begin(), res.end());
        for (auto i = res.begin(); i != res.end(); i++){
            cout << *i << " ";
        }
    }
    return 0;
}
