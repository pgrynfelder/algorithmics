#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5+7;
bool visited[N];
vector<int> G[N];

int dp[N][2]; // [vertex][taken?]

void dfs(int v){
    dp[v][1] = 1;
    for (int u : G[v]){
        if (!visited[u]){
            visited[u] = true;
            dfs(u);
            dp[v][0] += max(dp[u][0], dp[u][1]);
            dp[v][1] += dp[u][0];
        }
    }
    // cout << v << ": " << dp[v][0] << " " << dp[v][1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    visited[1] = true;
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}

