#include<bits/stdc++.h>
using namespace std;

vector<int> sorted;
vector<int> leaves;
vector<vector<int>> G;
vector<int> parent;

int dp[1000007][2];

void dfs(const int &v){
    bool has_children = false;
    for (int &u : G[v]){
        if (u != parent[v]){
            parent[u] = v;
            has_children = true;
            dfs(u);
        }
    }
    if (has_children){
        sorted.push_back(v);
    } else {
        leaves.push_back(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    G.resize(n+1);
    parent.resize(n+1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    parent[1] = 1;
    dfs(1);
    for (int &v : leaves){
        dp[v][0] = 0;
        dp[v][1] = 1;
    }
    //reverse(sorted.begin(), sorted.end());
    for (int &v : sorted){
        for (int &u : G[v]){
            if (u != parent[v]){
                dp[v][0] += max(dp[u][0], dp[u][1]);
                dp[v][1] += dp[u][0];
            }
        }
        dp[v][1]++;
    }
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}
