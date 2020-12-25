#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 7, LOGN = 20;
vector<int> G[N];
int n;

int jumpptr[N][LOGN];
int dist[N];
int p[N];

void dfs(int v) {
    for (int u : G[v]) {
        // careful here, Ród Bitockich adjusted, may need additional conditions
        // in other problems
        dist[u] = dist[v] + 1;
        jumpptr[u][0] = p[u];
        for (int i = 1; i < LOGN; i++) {
            jumpptr[u][i] = jumpptr[jumpptr[u][i - 1]][i - 1];
        }
        dfs(u);
    }
}

int lca(int a, int b) {
    if (dist[b] < dist[a])
        swap(a, b); //  so that b is deeper

    for (int i = LOGN - 1; i >= 0; i--) {
        if (dist[jumpptr[b][i]] >= dist[a]) {
            b = jumpptr[b][i];
        }
    }
    if (a == b)
        return a;

    for (int i = LOGN - 1; i >= 0; i--) {
        if (jumpptr[a][i] != jumpptr[b][i]) {
            a = jumpptr[a][i];
            b = jumpptr[b][i];
        }
    }
    return jumpptr[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        p[i] = a;
        G[a].push_back(i);
    }
    for (int i = 0; i < LOGN; i++) {
        jumpptr[0][i] = 0;
    }
    dfs(0);
    cout << lca(3, 4) << "\n";
    cout << lca(6, 4) << "\n";
    cout << lca(2, 8) << "\n";
    cout << lca(3, 1) << "\n";
    return 0;
}
