#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> dist;
vector<int> parent;
vector<int> maxchildren;
vector<int> minchildren;

const int LOG_N = 20;
const int N = 300007;
int jumpptr[N][LOG_N];
void dfs(){
    jumpptr[0][0] = 0;
    dist[0] = 0;
    stack<int> s;
    s.push(0);
    while (!s.empty()){
        int v = s.top(); s.pop();
        maxchildren[v] = max((int)G[v].size(), maxchildren[parent[v]]);
        minchildren[v] = min((int)G[v].size(), minchildren[parent[v]]);
        jumpptr[v][0] = parent[v];
        dist[v] = dist[parent[v]] + 1;
        for (int i = 1; i < LOG_N; i++)
        {
            jumpptr[v][i] = jumpptr[jumpptr[v][i-1]][i-1];
        }
        for (int u : G[v]){
            s.push(u);
        }
        
    }
}

int lca(int a, int b){
    if (dist[a] > dist[b]){
        swap(a,b);
    } // b's gotta always be lower than a
    for (int i = LOG_N-1; i >= 0; i--){
        if (dist[jumpptr[b][i]] >= dist[a]){
            b = jumpptr[b][i];
        }
    } // a and b are now on the same height
    // if (a==b) return a;
    // modified because the problem explicitly asks for ancestor
    
    for (int i = LOG_N-1; i >= 0; i--){
        if (jumpptr[a][i] != jumpptr[b][i]){
            a = jumpptr[a][i];
            b = jumpptr[b][i];
        }
    }
    return jumpptr[a][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    G.resize(n);
    dist.resize(n);
    parent.resize(n);
    maxchildren.resize(n);
    minchildren.resize(n, INT_MAX);
    parent[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        G[p].push_back(i);
        parent[i] = p;
    }

    dfs();
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        //cout << "LCA " << lca(a,b) << '\n';
        int xd = lca(a,b);
        cout << minchildren[xd]+1 << ' ' << maxchildren[xd]+1 << '\n';
    }
    return 0;
}
