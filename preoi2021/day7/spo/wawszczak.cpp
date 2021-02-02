#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1, LOGN = 18;

vector<int> graph[MAXN];
int siz[MAXN], depth[MAXN], heavy[MAXN], jump[MAXN][LOGN];

void dfs(int u) {
    for (int bit = 1; bit < LOGN; ++bit) {
        jump[u][bit] = jump[jump[u][bit - 1]][bit - 1];
    }

    siz[u] = 1;
    for (int v : graph[u]) {
        if (v != jump[u][0]) {
            depth[v] = depth[u] + 1;
            jump[v][0] = u;
            dfs(v);
            siz[u] += siz[v];
            if (siz[v] > siz[heavy[u]]) {
                heavy[u] = v;
            }
        }
    }
}

int where[MAXN], curr_pos = 0, chain_start[MAXN], chain_id[MAXN], curr_id = 1;

void hld(int u) {
    where[u] = ++curr_pos;

    if (heavy[u]) {
        chain_id[heavy[u]] = chain_id[u];
        hld(heavy[u]);
    }

    for (int v : graph[u]) {
        if (v != jump[u][0] && v != heavy[u]) {
            chain_start[++curr_id] = v;
            chain_id[v] = curr_id;
            hld(v);
        }
    }
}

int lca(int u, int v) {
    for (int bit = LOGN - 1; bit >= 0; --bit) {
        if (depth[jump[u][bit]] >= depth[v]) {
            u = jump[u][bit];
        }
    }
    for (int bit = LOGN - 1; bit >= 0; --bit) {
        if (depth[jump[v][bit]] >= depth[u]) {
            v = jump[v][bit];
        }
    }

    if (u == v) {
        return u;
    }

    for (int bit = LOGN - 1; bit >= 0; --bit) {
        if (jump[u][bit] != jump[v][bit]) {
            u = jump[u][bit];
            v = jump[v][bit];
        }
    }
    return jump[u][0];
}

const int BASE = 1 << LOGN;
struct segment_tree {
    int minn[BASE << 1];

    void insert(int l, int r, int val) {
        if (l <= r) {
            for (l += BASE, r += BASE + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    minn[l] = min(minn[l], val);
                    l++;
                }
                if (r & 1) {
                    r--;
                    minn[r] = min(minn[r], val);
                }
            }
        }
    }

    int query(int i) {
        int ans = INT_MAX;
        for (i += BASE; i > 0; i >>= 1) {
            ans = min(ans, minn[i]);
        }
        return ans;
    }
} tree;

int ans = 0;
long long total = 0;

void dfs2(int u) {
    ans++;
    for (int v : graph[u]) {
        if (v != jump[u][0]) {
            int tmp = tree.query(where[v]);
            if (tmp != INT_MAX) {
                total += tmp;
                dfs2(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    jump[1][0] = 1;
    dfs(1);

    chain_start[1] = chain_id[1] = 1;
    hld(1);

    for (int i = 1; i < BASE << 1; ++i) {
        tree.minn[i] = INT_MAX;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;

        int w = lca(u, v);

        while (chain_id[u] != chain_id[w]) {
            tree.insert(where[chain_start[chain_id[u]]], where[u], cost);
            u = jump[chain_start[chain_id[u]]][0];
        }
        if (u != w) {
            tree.insert(where[w] + 1, where[u], cost);
        }

        while (chain_id[v] != chain_id[w]) {
            tree.insert(where[chain_start[chain_id[v]]], where[v], cost);
            v = jump[chain_start[chain_id[v]]][0];
        }
        if (v != w) {
            tree.insert(where[w] + 1, where[v], cost);
        }
    }

    dfs2(1);
    cout << ans << ' ' << total;

    return 0;
}