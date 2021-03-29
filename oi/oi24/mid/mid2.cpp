/*
DOES NOT WORK

OI 24
MID

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+7, LOGN = 21;
int n, q, l[N], r[N], jptr[N][LOGN], mapping[N], d[N];

void dfs1(int a) {
    if (l[a] != 0) {
        if (mapping[a] == 1) mapping[l[a]] = 1;
        dfs1(l[a]);
    }
    if (r[a] != 0) {
        dfs1(r[a]);
    }
}

void dfs2(int a) {
    assert(mapping[a] != 0);

    int mapped = mapping[a];
    for (auto &child : {l, r}) {
        if (child[a] != 0) {
            if (child[mapped] == 0) {
                child[mapped] = child[a];
                mapping[child[a]] = child[a];
            } else {
                mapping[child[a]] = child[mapped];
            }
            dfs2(child[a]);
        }
    }
}

void dfs3(int a) {
    for (auto &child : {l, r}) {
        if (child[a] != 0) {
            d[child[a]] = d[a] + 1;

            jptr[child[a]][0] = a;
            for (int i = 1; i < LOGN; i++)
                jptr[child[a]][i] = jptr[jptr[a][i - 1]][i - 1];

            dfs3(child[a]);
        }
    }
}

// with money for a go to b (check a >= b)
bool solve(int a, int b) {
    if (d[b] > d[a]) return false;

    for (int i = LOGN - 1; i >= 0; i--) {
        if (d[jptr[a][i]] >= d[b]) a = jptr[a][i];
        if (d[jptr[b][i]] >= d[a]) b = jptr[b][i];
    }
    if (a == b) return true;

    for (int i = LOGN - 1; i >= 0; i--)
        if (jptr[a][i] != jptr[b][i]) a = jptr[a][i], b = jptr[b][i];

    int lca = jptr[a][0];
    if (b == l[lca]) {
        assert(a == r[lca]);
        return true;
    } else {
        assert(a == l[lca] and b == r[lca]);
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    mapping[1] = 1;
    dfs1(1);
    for (int i = 1; i <= n; i++)
        if (mapping[i] == 1) l[i] = 0;
    for (int i = 1; i <= n; i++)
        if (mapping[i] == 1) dfs2(i);

    for (int i = 0; i < LOGN; i++) jptr[1][i] = 1;
    dfs3(1);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (solve(mapping[a], mapping[b]) ? "TAK" : "NIE") << "\n";
    }
    return 0;
}

/*

7
2 3
4 5
6 7
0 0
0 0
0 0
0 0
6
4 5
5 4
5 6
6 5
6 7
7 6

*/