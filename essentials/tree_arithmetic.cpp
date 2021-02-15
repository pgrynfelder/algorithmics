// arithmetic sequence tree
// beware of long longs or smth
#include <bits/stdc++.h>
using namespace std;

struct seq {
    int a = 0, r = 0;
    seq operator+(const seq &b) const { return {a + b.a, r + b.r}; }
    void operator+=(const seq &b) { a += b.a, r += b.r; }

    // a + (a + r) + ... + a + (k-1) r
    long long sum(const int k) {
        return (2 * a + ((long long)k - 1) * r) * k / 2;
    }
};

constexpr seq def = {0, 0};

struct tree {
    int n = 1;
    vector<long long> t;
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
    long long _get(int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }

        push(r - l + 1, i);
        int m = (l + r) / 2;
        long long res = 0;
        if (a <= m) res += _get(l, m, i * 2);
        if (m + 1 <= b) res += _get(m + 1, r, i * 2 + 1);
        return res;
    }
    long long get(int _a, int _b) {
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
        return _add(0, n - 1, 1);
    }
};

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int n = 8;
    tree t(n);

    while (true) {
        seq x;
        int a, b;
        cin >> a >> b >> x.a >> x.r;
        t.add(a, b, x);
        for (int i = 0; i < n; i++) {
            cout << t.get(i, i) << " ";
        }
        cout << "\n";
    }

    return 0;
}