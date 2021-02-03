// segseg wawszczak
#include <bits/stdc++.h>
using namespace std;

template <typename T, T def, class op>
struct segment_tree {  // add x on interval variant
    int n = 1;
    vector<T> t, prop;

    segment_tree(int _n = 1) {
        while (n < _n) n <<= 1;
        t.assign(n << 1, def);
        prop.assign(n << 1, 0);
    }

    void propagate(int i) {
        if (i < n) {
            ...
        }
    }

    void update(int i) {
        if (i < n) {
            t[i] = op(t[i << 1], t[i << 1 ^ 1]);
        }
    }

    int x, a, b;

    void _set(int l, int r, int i) {
        if (a <= l and r <= b) {
            t[i] = x;
            return;
        }

        propagate(i);

        int m = l + r >> 1;
        if (a <= m) {
            _set(l, m, i << 1);
        }
        if (m + 1 <= b) {
            _set(m + 1, r, i << 1 ^ 1);
        }

        update(i);
    }

    void set(int _a, int _b, int _x) {
        a = _a, b = _b, x = _x;
        _set(0, n - 1, 1);
    }

    int _get(int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }

        propagate(i);

        T res = def;
        int m = l + r >> 1;
        if (a <= m) {
            res = op(res, _get(l, m, i << 1));
        }
        if (m + 1 <= b) {
            res = op(res, _get(m + 1, r, i << 1 ^ 1));
        }

        return res;
    }

    T get(int _a, int _b) {
        a = _a, b = _b;
        return _get(0, n - 1, 1);
    }
};

struct op {
    long long operator()(long long a, long long b) { return min(a, b); }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    segment_tree<long long, (long long)(1e9 + 7), op> t;
    return 0;
}