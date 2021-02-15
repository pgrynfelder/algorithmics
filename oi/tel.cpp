// arithmetic sequence tree
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct seq {
    ll a = 0, r = 0;
    seq operator+(const seq &b) const { return {a + b.a, r + b.r}; }
    void operator+=(const seq &b) { a += b.a, r += b.r; }

    // a + (a + r) + ... + a + (k-1) r
    ll sum(const int k) { return (2 * a + (k - 1) * r) * k / 2; }
};

constexpr seq def = {0, 0};

struct tree {
    int n = 1;
    vector<ll> t;
    vector<seq> prop;
    tree(int _n) {
        while (n < _n) n *= 2;
        t.resize(n * 2);
        prop.resize(n * 2);
    }
    void push(int len, int i) {
        if (i < n) {
            seq rightprop = {prop[i].a + len / 2 * prop[i].r, prop[i].r};
            prop[2 * i] += prop[i];
            prop[2 * i + 1] += rightprop;
            t[2 * i] += prop[i].sum(len / 2);
            t[2 * i + 1] += rightprop.sum(len / 2);
            prop[i] = def;
        }
    }
    void update(int i) { t[i] = t[2 * i] + t[2 * i + 1]; }

    int a, b;
    ll _get(int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }

        push(r - l + 1, i);
        int m = (l + r) / 2;
        ll res = 0;
        if (a <= m) res += _get(l, m, i * 2);
        if (m + 1 <= b) res += _get(m + 1, r, i * 2 + 1);
        return res;
    }
    ll get(int _a, int _b) {
        a = _a, b = _b;
        return _get(0, n - 1, 1);
    }
    seq x;
    void _add(int l, int r, int i) {
        if (a <= l and r <= b) {
            seq toadd = {x.a + (l - a) * x.r, x.r};
            t[i] += toadd.sum(r - l + 1);
            prop[i] += toadd;
            return;
        }
        push(r - l + 1, i);
        int m = (l + r) / 2;
        if (a <= m) _add(l, m, 2 * i);
        if (m + 1 <= b) _add(m + 1, r, 2 * i + 1);
        update(i);
    }
    void add(int _a, int _b, seq _x) {
        a = _a, b = _b, x = _x;
        if (a > b) return;
        if (a < 0) {
            x = {x.a - a * x.r, x.r};
            a = 0;
        }
        return _add(0, n - 1, 1);
    }
};

int n, m;
constexpr int N = 3e5 + 7;
int s[N], a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    tree t(n + 1);

    while (m--) {
        char c;
        cin >> c;
        if (c == 'P') {
            int i;
            cin >> i;
            cin >> s[i] >> a[i];
            int lo = s[i] % a[i];
            int l = i - s[i] / a[i];
            t.add(l, i, {lo, a[i]});
            t.add(i + 1, i + (i - l), {s[i] - a[i], -a[i]});
        } else if (c == 'U') {
            int i;
            cin >> i;
            int lo = s[i] % a[i];
            int l = i - s[i] / a[i];
            t.add(l, i, {-lo, -a[i]});
            t.add(i + 1, i + (i - l), {-(s[i] - a[i]), a[i]});
        } else if (c == 'Z') {
            int l, r;
            cin >> l >> r;
            cout << (long long)(t.get(l, r) / (r - l + 1)) << '\n';
        }
    }

    return 0;
}