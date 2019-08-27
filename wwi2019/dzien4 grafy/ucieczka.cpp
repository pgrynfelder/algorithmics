#include<bits/stdc++.h>
using namespace std;

vector<int> amodist;
vector<int> amo;
vector<vector<int>> G;

void bfs(){
    queue<int> Q;
    for (int a : amo){
        Q.push(a);
    }
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();        
        for (int u : G[v]){
            if (amodist[v]+1 < amodist[u]){
                amodist[u] = amodist[v] + 1;
                Q.push(u);
            }
        }
    }
};

const int LOG_N = 20;
const int N = 200007;
vector<int> dist;
int jumpptr[N][LOG_N];
int jumpmin[N][LOG_N];
void dfs(int v, int p){
    jumpptr[v][0] = p;
    jumpmin[v][0] = min(amodist[v], amodist[p]);
    dist[v] = dist[p] + 1;
    for (int i = 1; i < LOG_N; i++)
    {
        jumpptr[v][i] = jumpptr[jumpptr[v][i-1]][i-1];
        jumpmin[v][i] = min(jumpmin[v][i-1], jumpmin[jumpptr[v][i-1]][i-1]);

    }
    for (int u : G[v]){
        if (u != p) dfs(u, v);
    }
}

pair<int, int> lca(int a, int b){
    int minimum = INT_MAX;
    if (dist[a] > dist[b]){
        swap(a, b);
    }

    for (int i = LOG_N-1; i >= 0; i--){
        if (dist[jumpptr[b][i]] >= dist[a]){
            minimum = min(minimum, jumpmin[b][i]);
            b = jumpptr[b][i];
        }
    }
    if (a==b) return {a, minimum};

    for (int i = LOG_N-1; i >= 0; i--){
        if (jumpptr[a][i] != jumpptr[b][i]){
            minimum = min(minimum, min(jumpmin[a][i], jumpmin[b][i]));
            a = jumpptr[a][i];
            b = jumpptr[b][i];
        }
    }
    return {jumpptr[a][0], min(minimum, min(jumpmin[a][0], jumpmin[b][0]))};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin >> n;
    amodist.resize(n+1, INT_MAX);
    G.resize(n+1);
    dist.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> m;
    amo.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> amo[i];
        amodist[amo[i]] = 0;
    }
    //cout << "PREPROCESSING\n";
    bfs();
    dfs(1,1);
    //cout << "ACTUAL\n";
    cin >> q;
    while (q--){
        int a,b;
        cin >> a >> b;
        auto p  = lca(a, b);
        //cout << p.first << ' ';
        cout << dist[a] + dist[b] - 2*dist[p.first] + 2*p.second << '\n';
    }
    return 0;
}
/*
6
1 2
2 3
1 4
5 4
6 4
1 2
4
1 4
3 1
2 4
5 6
*/
