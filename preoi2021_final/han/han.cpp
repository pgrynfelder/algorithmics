#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
constexpr long long M = 1e9 + 7;

map<int, int> scale;
long long pow2[2 * N];

struct tree {
    int n = 1;
    vector<long long> t, mod;
    tree(int _n) {
        while (n < _n) n *= 2;
        t.resize(n * 2);
        mod.resize(n * 2);
    }
    void update(int i) {
        if (i < n) {
            t[i] = (t[i * 2] * pow2[mod[i * 2]] +
                    t[i * 2 + 1] * pow2[mod[i * 2 + 1]]) %
                   M;
        }
    }
    int a, b;
    long long x;
    void _shift(int l, int r, int i) {
        if (a <= l and r <= b) {
            mod[i] += x;
            return;
        }
        int m = (l + r) / 2;
        if (a <= m) _shift(l, m, i * 2);
        if (m + 1 <= b) _shift(m + 1, r, i * 2 + 1);
        update(i);
    }
    void shift(long long _x, int _a, int _b = -1) {
        a = _a, b = _b;
        x = _x;
        if (b == -1) b = n - 1;
        _shift(0, n - 1, 1);
    }
    void add(int i) {
        if (t[i + n] == 0) {
            shift(+1, i + 1);
        }
        t[i + n]++;
        i += n;
        while (i > 1) {
            i /= 2;
            update(i);
        }
    }
    void remove(int i) {
        t[i + n]--;
        if (t[i + n] == 0) {
            shift(-1, i + 1);
        }
        i += n;
        while (i > 1) {
            i /= 2;
            update(i);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> start(n), qs(q);
    for (int &a : start) {
        cin >> a;
        scale[a] = 0;
    }
    for (int &a : qs) {
        cin >> a;
        scale[abs(a)] = 0;
    }

    int i = scale.size();
    for (auto &[key, val] : scale) val = i--;

    for (int &a : start) a = scale[a];
    for (int &a : qs) {
        if (a >= 0)
            a = scale[a];
        else
            a = -scale[-a];
    }
    pow2[0] = 1;
    for (int i = 1; i <= scale.size(); i++) pow2[i] = pow2[i - 1] * 2 % M;

    tree t(scale.size() + 1);
    for (int a : start) {
        t.add(a);
    }
    for (int a : qs) {
        if (a >= 0)
            t.add(a);
        else
            t.remove(-a);
        cout << t.t[1] << "\n";
    }

    return 0;
}

/*

2 3
2 3
+4
-2
+3

*/