#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 7, T = 1e6 + 7, oo = 1e6 + 9;

struct Tree {
    int n = 1;
    int def;
    function<int(int, int)> op;
    vector<int> t;
    Tree(int _n, int _def, function<int(int, int)> _op) {
        while (n < _n) {
            n <<= 1;
        }
        def = _def;
        op = _op;
        t.resize(n << 1, def);
    }
    int get(int a, int b, int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }
        int res = def;
        int m = (l + r) / 2;
        if (a <= m) {
            res = op(res, get(a, b, l, m, i << 1));
        }
        if (m + 1 <= b) {
            res = op(res, get(a, b, m + 1, r, (i << 1) + 1));
        }
        return res;
    }
    int get(int a, int b) { return get(a, b, 0, n - 1, 1); }

    void update(int x, int i) {
        i += n;
        t[i] = x;
        while (i > 1) {
            i >>= 1;
            t[i] = op(t[i << 1], t[(i << 1) + 1]);
        }
    }
};

int n, t, q;
vector<int> tab;
vector<set<int>> where;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    Tree tmin(n + 1, oo, [](const int &a, const int &b) { return min(a, b); });
    Tree tmax(n + 1, 0, [](const int &a, const int &b) { return max(a, b); });
    Tree nxt(n + 1, oo, [](const int &a, const int &b) { return min(a, b); });
    where.resize(t + 1, {0, oo});
    tab.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tab[i] = x;
        tmin.update(x, i);
        tmax.update(x, i);
        where[x].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        int x = tab[i];
        auto it = where[x].find(i);
        nxt.update(*next(it), i);
    }
    cin >> q;
    for (int j = 1; j <= q; j++) {
        int k;
        cin >> k;
        if (k == 2) {
            int i, x;
            cin >> i >> x;

            int old = tab[i];
            auto oldit = where[old].find(i);
            nxt.update(*next(oldit), *prev(oldit));
            where[old].erase(oldit);

            tab[i] = x;
            tmin.update(x, i);
            tmax.update(x, i);
            auto [it, _] = where[x].insert(i);
            nxt.update(*it, *prev(it));
            nxt.update(*next(it), *it);
        } else if (k == 1) {
            int l, r;
            cin >> l >> r;
            if (r - l != tmax.get(l, r) - tmin.get(l, r)) {
                cout << "NO\n";
                continue;
            }
            // cout << nxt.get(l, r);
            if (nxt.get(l, r) <= r) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
        }
    }
    return 0;
}

/*
5 10
4 4 3 5 7
3
1 2 4
1 1 3
1 1 5

YES
NO
NO

3 150
1 1 1
5
2 1 100
2 2 102
1 1 3
2 3 101
1 1 3

NO
YES



*/