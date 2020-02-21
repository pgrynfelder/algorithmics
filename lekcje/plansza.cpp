#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7, M = 4e5 + 7;
vector<pair<int,int>> G[N]; 
bool deg[N];
int n, m;
int val[M];
int last[N];
bool visitedE[M];
bool visitedV[N];
stack<pair<int,int>> res;
void euler(int v, int p){
    for ( ; last[v] < G[v].size(); last[v]++){
        auto &e = G[v][last[v]];
        if (!visitedE[e.second]){
            visitedE[e.second] = 1;
            visitedV[e.first] = 1;
            euler(e.first, e.second);
        }
    }
    // cout << p << " ";
    res.emplace(v, p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        b += n;
        deg[a] ^= 1; deg[b] ^= 1;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    queue<int> q;
    for (int i = 1; i <= (n<<1); i++){
        if (deg[i]) q.emplace(i);
    }
    int i = m + 1;
    while (q.size() > 1){
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        deg[a] ^= 1; deg[b] ^= 1;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
        i++;
    }
    for (int i = 1; i <= (n<<1); i++){
        if (!visitedV[i]){
            euler(i, 0);
            res.pop();
            while (!res.empty()){
                auto e = res.top(); res.pop();
                if (e.first <= n){
                    val[e.second] = 1;
                }
                else {
                    val[e.second] = -1;
                }
            }
        }
    }
    cout << "TAK\n";
    for (int i = 1; i <= m; i++){
        cout << val[i] << "\n";
    }
    return 0;
}
