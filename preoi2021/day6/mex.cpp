#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e3 + 7;

struct edge {
    int v = 0, i = 0;
    edge(int _v, int _i) {
        v = _v;
        i = _i;
    }
};

struct rng {
    int l = 0, r = 0;
    rng(int _l, int _r) {
        l = _l;
        r = _r;
    }
    bool extend(rng &other) {
        if (not canextend(other))
            return false;
        l = min(l, other.l);
        r = max(r, other.r);
        return true;
    }
    bool canextend(rng &other) { return other.l <= r + 1 and l <= other.r + 1; }
};

int n;
vector<edge> G[N];
set<rng> dp[N];
bool vis[N];

void dfs(int v){
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b, i >> 1);
    }

    return 0;
}