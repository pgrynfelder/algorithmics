/*
    Piotr Grynfelder
    SZA
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e3 + 7, LOGN = 11;
constexpr long long p1 = 107, mod1 = 10000000069, p2 = 109, mod2 = 1000000007;

struct edge {
    int a = 0, i = 0;
    edge(int _a, int _i) { a = _a, i = _i; }
};
char letter[N];
vector<edge> g[N];

long long H1[N][N], H2[N][N];

int parentedge[N];

// hld inspirowane cp-algorithms i ze staszicowych kółek
int jump[N][LOGN], d[N], s[N], heavy[N];

void dfs(int a) {
    s[a] = 1;
    for (auto [b, e] : g[a]) {
        if (jump[a][0] != b) {
            d[b] = d[a] + 1;
            parentedge[b] = e;
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
    for (auto [b, e] : g[a]) {
        if (b != jump[a][0] and b != heavy[a]) {
            cur_id++;
            head[cur_id] = b;
            chain[b] = cur_id;

            hld(b);
        }
    }
}
constexpr int def = 1e9 + 7;
template <typename T>
struct tree {
    int n = 1;
    vector<T> t, prop;
    tree(int _n = 1) {
        while (n < _n) n *= 2;
        t.assign(n * 2, def);
        prop.assign(n * 2, def);
    }
    void propagate(int i) {
        if (i < n and prop[i] != def) {
            t[2 * i] = t[2 * i + 1] = prop[2 * i] = prop[2 * i + 1] = prop[i];
            prop[i] = def;
        }
    }
    void update(int i) {
        if (i < n) {
            t[i] = min(t[i * 2], t[i * 2 + 1]);
        }
    }
    T x;
    int a, b;
    void _set(int l, int r, int i) {
        if (a <= l and r <= b) {
            t[i] = x;
            prop[i] = x;
            return;
        }
        int m = (l + r) / 2;
        propagate(i);
        if (a <= m) _set(l, m, i * 2);
        if (m + 1 <= b) _set(m + 1, r, i * 2 + 1);
        update(i);
    }
    void set(int _a, int _b, T _x) {
        a = _a;
        b = _b;
        x = _x;
        return _set(0, n - 1, 1);
    }
    T _get(int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }
        int m = (l + r) / 2;
        T res = def;
        propagate(i);
        if (a <= m) res = min(res, _get(l, m, i * 2));
        if (m + 1 <= b) res = min(res, _get(m + 1, r, i * 2 + 1));
        return res;
    }
    T get(int _a, int _b) {
        a = _a;
        b = _b;
        return _get(0, n - 1, 1);
    }
    T get() { return t[1]; }
    void print() {
        for (int i = 1; i < 2 * n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }
};

void dfshash(int a, int p, int sos) {
    for (auto [b, e] : g[a]) {
        if (b != p) {
            H1[sos][b] = (H1[sos][p] * p1 + letter[e]) % mod1;
            H2[sos][b] = (H2[sos][p] * p2 + letter[e]) % mod2;
            dfshash(b, a, sos);
        }
    }
}

int n;

void hldset(int a, int b, int x, tree<int> &t) {
    int c = lca(a, b);
    while (chain[a] != chain[c]) {
        t.set(where[head[chain[a]]], where[a], x);
        a = jump[head[chain[a]]][0];
    }
    if (c != a) t.set(where[c] + 1, where[a], x);

    while (chain[b] != chain[c]) {
        t.set(where[head[chain[b]]], where[b], x);
        b = jump[head[chain[b]]][0];
    }
    if (c != b) t.set(where[c] + 1, where[b], x);
}

set<string> ANS;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        char l;
        cin >> a >> b >> l;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
        letter[i] = l;
    }

    for (int i = 1; i <= n; i++) dfshash(i, i, i);  // policz hashe

    vector<pair<int, int>> M, ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            M.emplace_back(i, j);
        }
    }
    sort(M.begin(), M.end(),
         [&](const pair<int, int> &a, const pair<int, int> &b) {
             auto [i, j] = a;
             auto [x, y] = b;
             return H1[i][j] < H1[x][y] or
                    (H1[i][j] == H1[x][y] and H2[i][j] < H2[x][y]);
         });

    jump[1][0] = 1;
    dfs(1);
    vector<int> visited(n + 1);
    int xd = 1;
    auto [prev_a, prev_b] = *M.begin();
    for (auto it = M.begin(); it != M.end(); it++) {
        auto [a, b] = *it;
        if (H1[a][b] != H1[prev_a][prev_b] or H2[a][b] != H2[prev_a][prev_b]) {
            bool works = true;
            for (int i = 1; i < n; i++) {
                works = works and visited[i] == xd;
            }
            if (works) ans.emplace_back(prev_a, prev_b);
            xd++;
        }
        int c = lca(a, b);
        while (a != c) {
            visited[parentedge[a]] = xd;
            a = jump[a][0];
        }
        while (b != c) {
            visited[parentedge[b]] = xd;
            b = jump[b][0];
        }
        prev_a = a;
        prev_b = b;
    }
    bool works = true;
    for (int i = 1; i < n; i++) {
        works = works and visited[i] == xd;
    }
    if (works) ans.emplace_back(prev_a, prev_b);
    for (auto [a, b] : ans) {
        int c = lca(a, b);
        string s1 = "", s2 = "";
        while (a != c) {
            s1 += letter[parentedge[a]];
            a = jump[a][0];
        }
        while (b != c) {
            s2 += letter[parentedge[b]];
            b = jump[b][0];
        }
        reverse(s2.begin(), s2.end());
        ANS.emplace(s1 + s2);
    }

    cout << ANS.size() << "\n";
    for (string s : ANS) {
        cout << s << "\n";
    }
    return 0;
}

/*

13
1 2 A
1 3 A
2 4 B
3 5 B
4 6 A
4 7 A
5 8 A
5 9 A
6 10 B
7 11 B
8 12 B
13 9 B

*/