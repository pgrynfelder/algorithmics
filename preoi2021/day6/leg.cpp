#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7;
constexpr long long oo = (2e5 + 7) * (1e9 + 7);

int L[N], R[N];
long long c[N], d[N];
bool vis[N];

struct tree {
    int n = 1;
    vector<pair<long long, int>> t, star;
    tree(int _n) {
        while (n < _n)
            n <<= 1;
        t.resize(n << 1);
        star.resize(n << 1);
        for (int i = n; i < n << 1; i++) {
            star[i] = t[i] = {oo, i - n};
        }
        for (int i = n - 1; i > 0; i--) {
            star[i] = t[i] = min(t[i << 1], t[(i << 1) + 1]);
        }
    }
    void prop(int i) {
        t[i << 1] = min(star[i], t[i << 1]);
        t[(i << 1) + 1] = min(star[i], t[(i << 1) + 1]);
        star[i << 1] = min(star[i], star[i << 1]);
        star[(i << 1) + 1] = min(star[i], star[(i << 1) + 1]);
    }
    void set(int a, int b, int l, int r, int i, long long x) {

        if (a > r or b < l) {
            return;
        }
        if (t[i].first > x) {
            t[i].first = x;
        }
        if (a <= l and r <= b and t[i].first >= x) {
            star[i].first = x;
            t[i].first = x;
            return;
        }
        if (l == r) {
            return;
        }
        prop(i);
        int m = (l + r) >> 1;

        set(a, b, l, m, i << 1, x);
        set(a, b, m + 1, r, (i << 1) + 1, x);
    }
    void set(int a, int b, long long x) { set(a, b, 0, n - 1, 1, x); }

    pair<long long, int> read(int a, int b, int l, int r, int i) {
        if (a > r or b < l) {
            return {oo, n};
        }
        if (a <= l and r <= b) {
            return t[i];
        }
        prop(i);
        int m = (l + r) >> 1;
        return min(read(a, b, l, m, i << 1),
                   read(a, b, m + 1, r, (i << 1) + 1));
    }
    pair<long long, int> read(int a, int b) { return read(a, b, 0, n - 1, 1); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> L[i];
        for (int i = 1; i <= n; i++)
            cin >> R[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++) {
            d[i] = oo;
            vis[i] = false;
        }
        tree t(n + 1);
        t.set(1, 1, 0);
        int viscount = 0;
        auto xd = t.read(1, n);
        auto dist = xd.first;
        auto a = xd.second;
        while (dist < oo) {
            if (vis[a]) {
                t.set(a, a, oo);
                continue;
            }
            d[a] = dist;
            vis[a] = true;
            t.set(a, a, oo);

            int lo = max(1, a - R[a]), hi = a - L[a];
            if (hi >= lo) {
                t.set(lo, hi, dist + c[a]);
            }
            lo = a + L[a], hi = min(n, a + R[a]);
            if (hi >= lo) {
                t.set(lo, hi, dist + c[a]);
            }
            xd = t.read(1, n);
            dist = xd.first;
            a = xd.second;
        }
        for (int i = 1; i <= n; i++) {
            cout << (d[i] != oo ? d[i] : -1) << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*

3
3
1 1 1
1 1 1
1 1 1
2
0 1
0 1
1 1
5
2 0 0 0 1
3 1 1 0 5
1 1 1 1 1

*/