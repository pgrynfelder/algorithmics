/*
WYS
26 OI
https://szkopul.edu.pl/problemset/problem/S8phA644ooC9arh6FhXzvbiH/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

int n, q;
constexpr long long oo = 1e18 + 1e9 + 7;
vector<long long> scores;

template <typename T>
struct tree {
    vector<T> t, prop;
    int n = 1;
    tree(vector<T> &init) {
        int _n = init.size();
        while (n < _n) n *= 2;
        t.resize(2 * n, -oo);
        prop.resize(2 * n, 0);
        for (int i = 0; i < _n; i++) t[i + n] = init[i];
        for (int i = n - 1; i > 0; i--) update(i);
    }
    void propagate(int i) {
        if (i < n) {
            prop[i * 2] += prop[i];
            prop[i * 2 + 1] += prop[i];
            t[i * 2] += prop[i];
            t[i * 2 + 1] += prop[i];
            prop[i] = 0;
        }
    }
    void update(int i) {
        if (i < n) {
            t[i] = max(t[i * 2], t[i * 2 + 1]);
        }
    }
    int a, b;
    T x;
    T _read(int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }
        propagate(i);
        int m = (l + r) / 2;
        T res = -oo;
        if (a <= m) res = max(res, _read(l, m, i * 2));
        if (m + 1 <= b) res = max(res, _read(m + 1, r, i * 2 + 1));
        return res;
    }
    T read(int _a, int _b) {
        a = _a, b = _b;
        return _read(0, n - 1, 1);
    }
    void _add(int l, int r, int i) {
        if (a <= l and r <= b) {
            prop[i] += x;
            t[i] += x;
            return;
        }
        propagate(i);
        int m = (l + r) / 2;
        if (a <= m) _add(l, m, i * 2);
        if (m + 1 <= b) _add(m + 1, r, i * 2 + 1);
        update(i);
    }
    void add(T _x, int _a, int _b) {
        x = _x;
        a = _a, b = _b;
        if (a <= b) return _add(0, n - 1, 1);
    }
    int lower_bound(T x) {
        int i = 1;
        while (i < n) {
            propagate(i);
            if (t[i * 2] < x)
                i = i * 2 + 1;
            else
                i = i * 2;
        }
        if (t[i] < x) return i - n + 1;
        return i - n;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    scores.resize(n);
    for (auto &a : scores) {
        cin >> a;
    }
    sort(scores.begin(), scores.end());

    tree<long long> original(scores);
    for (int i = 1; i <= n; i++) {
        scores[n - i] += i;
    }
    tree<long long> modified(scores);
    while (q--) {
        char c;
        cin >> c;
        if (c == 'Z') {
            long long x = modified.read(0, n - 1) - n;
            cout << n - original.lower_bound(x) << "\n";
        } else if (c == 'B') {
            long long lb, toadd;
            cin >> lb >> toadd;
            int j = original.lower_bound(lb);
            original.add(toadd, j, n - 1);
            modified.add(toadd, j, n - 1);
        } else if (c == 'K') {
            long long ub, tosubtract;
            cin >> ub >> tosubtract;
            int j = original.lower_bound(ub + 1) - 1;
            original.add(-tosubtract, 0, j);
            modified.add(-tosubtract, 0, j);
        }
    }
    return 0;
}