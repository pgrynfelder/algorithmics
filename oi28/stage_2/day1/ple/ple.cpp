#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
constexpr long long oo = 5e15 + 7;

long long W[N], C[N];

template <typename T>
struct tree {
    int n = 1;
    vector<T> t, prop;
    tree(int _n) {
        while (n < _n) {
            n *= 2;
        }
        t.assign(n * 2, oo);
        prop.assign(n * 2, 0);
    }
    void propagate(int i) {
        if (i < n) {
            t[2 * i] += prop[i];
            t[2 * i + 1] += prop[i];
            prop[2 * i] += prop[i];
            prop[2 * i + 1] += prop[i];
            prop[i] = 0;
        }
    }
    void update(int i) {
        if (i < n) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    int a, b;
    T x;
    void _add(int l, int r, int i) {
        if (a <= l and r <= b) {
            t[i] += x;
            prop[i] += x;
            return;
        }
        propagate(i);
        int m = (l + r) / 2;
        if (a <= m) _add(l, m, 2 * i);
        if (m + 1 <= b) _add(m + 1, r, 2 * i + 1);
        update(i);
    }
    void add(int _a, int _b, T _x) {
        a = _a;
        b = _b;
        x = _x;
        _add(0, n - 1, 1);
    }

    T c;
    int _find(int i) {
        if (i >= n) return i - n;
        propagate(i);
        if (t[2 * i] <= t[2 * i + 1] + c) {
            return _find(2 * i);
        } else {
            return _find(2 * i + 1);
        }
    }
    int find(T _c) {
        c = _c;
        return _find(1);
    }
};

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    tree<long long> t(n + 1);
    t.add(1, n, -oo);
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
        t.add(i, i, W[i]);
    }
    long long c = 0;
    for (int k = 1; k <= n; k++) {
        int j = t.find(0);
        c += W[j];
        t.add(j + 1, n, +W[j]);
        t.add(j, j, oo);
        cout << j << ": " << W[j] << "\n";
        // cout << c << " ";
    }

    return 0;
}
