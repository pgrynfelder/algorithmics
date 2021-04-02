/*
PREOI 2021 FINAL
PRZ

subtask 1, 4
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7;
// constexpr int N = 20;
int n, q, l[N], r[N], d1[N], d2[N], x, comp[N];
pair<int, int> maxd[N], e[N];
vector<int> g[N];
set<int> v;

void dfs1(int a) {
    for (int b : g[a]) {
        if (!comp[b]) {
            comp[b] = comp[a];
            d1[b] = d1[a] + 1;
            dfs1(b);
        }
    }
}

bool visited[N];
void dfs2(int a) {
    for (int b : g[a]) {
        if (!visited[b]) {
            visited[b] = true;
            d2[b] = d2[a] + 1;
            dfs2(b);
        }
    }
}

void reset() {
    for (int a : v) {
        g[a].clear();
        d1[a] = 0;
        d2[a] = 0;
        comp[a] = 0;
        maxd[a] = {0, 0};
        visited[a] = 0;
    }
    v.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        e[i] = {a, b};
    }

    for (int i = 1; i <= q; i++) {
        cin >> x;
        for (int i = 1; i <= n - 1; i++) {
            auto [a, b] = e[i];
            if (l[a] <= x and x <= r[a] and l[b] <= x and x <= r[b]) {
                g[a].emplace_back(b);
                g[b].emplace_back(a);
                v.insert(a);
                v.insert(b);
            }
        }
        for (int a : v) {
            if (!comp[a]) {
                comp[a] = a;
                d1[a] = 0;
                dfs1(a);
            }
        }
        for (int a : v) {
            maxd[comp[a]] = max(maxd[comp[a]], pair(d1[a], a));
        }
        for (int a : v) {
            if (comp[a] == a) {
                visited[maxd[a].second] = true;
                dfs2(maxd[a].second);
            }
        }
        int res = 0;
        for (int a : v) {
            res = max(res, d2[a]);
        }
        cout << res << "\n";

        reset();
    }

    return 0;
}

/*

9 5
1 3 2 5 1 2 3 10 6
4 7 8 11 2 3 5 12 10
1 2
3 1
7 2
9 3
3 5
6 3
4 8
1 4
3
12
11
2
13

*/