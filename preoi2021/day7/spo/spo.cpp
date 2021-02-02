// hld seg-point

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7, LOGN = 18;
constexpr long long oo = 1e18 + 7;

int n, m;
vector<int> G[N];

int jump[N][LOGN], d[N], s[N], heavy[N];

void dfs(int a) {
    s[a] = 1;
    for (int b : G[a]) {
        if (jump[a][0] != b) {
            d[b] = d[a] + 1;
            jump[b][0] = a;
            for (int i = 1; i < LOGN; i++) {
                jump[b][i] = jump[jump[b][i - 1]][i - 1];
            }
            dfs(b);
            s[a] += s[b];
            if (s[b] > s[heavy[a]]) {
                heavy[a] = b;
            }
        }
    }
}
int lca(int a, int b) {
    if (d[b] < d[a]) swap(a, b);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (d[jump[b][i]] >= d[a]) {
            b = jump[b][i];
        }
    }
    if (a == b) return a;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (jump[a][i] != jump[b][i]) {
            a = jump[a][i];
            b = jump[b][i];
        }
    }
    return jump[a][0];
}
int cur_pos = 0, cur_id = 1,
    chain[N],  // chain idx of vertex c
    head[N],   // head of chain i
    where[N];  // where is c in the tree

void hld(int a) {
    cur_pos++;
    where[a] = cur_pos;
    if (heavy[a]) {
        chain[heavy[a]] = chain[a];  // lengthen the current chain
        hld(heavy[a]);
    }
    for (int b : G[a]) {
        if (b != jump[a][0] and b != heavy[a]) {
            cur_id++;
            head[cur_id] = b;
            chain[b] = cur_id;

            hld(b);
        }
    }
}

template <typename T, T def>
struct tree {
    int n = 1;
    vector<T> t;
    tree(int _n = 1) {
        while (n < _n) n <<= 1;
        t.assign(n << 1, def);
    }
    void set(T x, int a, int b, int l, int r, int i) {
        if (a <= l and r <= b) {
            t[i] = min(t[i], x);
            return;
        }
        int m = (l + r) >> 1;
        if (a <= m) set(x, a, b, l, m, i << 1);
        if (m + 1 <= b) set(x, a, b, m + 1, r, i << 1 ^ 1);
    }
    void set(int a, int b, int x) { return set(x, a, b, 0, n - 1, 1); }
    T get(int i) {
        i += n;
        T res = def;
        while (i > 0) {
            res = min(res, t[i]);
            i >>= 1;
        }
        return res;
    }
};

tree<long long, oo> t;

pair<int, long long> solve(int a) {
    int s = 1;
    long long total = 0;
    for (int b : G[a]) {
        if (b != jump[a][0]) {
            auto cost = t.get(where[b]);
            if (cost < oo) {
                total += cost;
                auto [x, d] = solve(b);
                s += x;
                total += d;
            }
        }
    }
    return {s, total};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    jump[1][0] = 1;
    dfs(1);
    head[1] = chain[1] = 1;
    hld(1);

    t = tree<long long, oo>(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        long long cost;
        cin >> a >> b >> cost;
        int c = lca(a, b);

        while (chain[a] != chain[c]) {
            t.set(where[head[chain[a]]], where[a], cost);
            a = jump[head[chain[a]]][0];
        }
        if (c != a) t.set(where[c] + 1, where[a], cost);

        while (chain[b] != chain[c]) {
            t.set(where[head[chain[b]]], where[b], cost);
            b = jump[head[chain[b]]][0];
        }
        if (c != b) t.set(where[c] + 1, where[b], cost);
    }

    auto [res1, res2] = solve(1);
    cout << res1 << " " << res2;

    return 0;
}

/*

5 2
1 2
1 3
2 4
2 5
1 4 3
2 3 4

4 10

*/