#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7, oo = 1e8 + 7;

int W[N];
int Z[N];
int n, q;

struct digit {
    int rot = 0;
    int e[10] = {oo, oo, oo, oo, oo, oo, oo, oo, oo, oo};
    int earliest(int i) const {
        i -= rot;
        if (i < 0) i += 10;
        return e[i];
    }
    void rotate(int x) {
        rot = (rot + x) % 10;
        if (rot < 0) rot += 10;  // can be optimised
    }
    digit operator+(const digit& other) const {
        digit res = digit();
        for (int d = 0; d < 10; d++) {
            res.e[d] = min(earliest(d), other.earliest(d));
        }
        return res;
    }
    int val() const {
        return rot;  // rot is the first occuring digit at base level because we
                     // initialise them at 0 and don't change later
    }
};

struct tree {
    int n = 1;
    vector<digit> t;
    tree(int _n) {
        while (n < _n) {
            n <<= 1;
        }
        t = vector<digit>(n << 1);
        for (int i = 0; i < n; i++) {
            t[i + n].e[0] = i;
        }

        for (int i = n - 1; i > 0; i--) {
            update(i);
        }
    }

    void push(int i) {
        t[(i << 1)].rotate(t[i].rot);
        t[(i << 1) + 1].rotate(t[i].rot);
    }

    void update(int i) { t[i] = t[(i << 1)] + t[(i << 1) + 1]; }

    void rotate(int a, int b, int l, int r, int i, int x) {
        if (a <= l and r <= b) {
            t[i].rotate(x);
            return;
        }
        int m = (l + r) / 2;
        if (a <= m or m + 1 <= b) {
            push(i);
            if (a <= m) rotate(a, b, l, m, (i << 1), x);
            if (m + 1 <= b) rotate(a, b, m + 1, r, (i << 1) + 1, x);
            update(i);
        }
    }
    void rotate(int a, int b, int x) { return rotate(a, b, 0, n - 1, 1, x); }
    void rotate(int a, int x) { return rotate(a, a, 0, n - 1, 1, x); }

    digit get(int a, int b, int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }
        int m = (l + r) / 2;
        if (a <= m or m + 1 <= b) {
            push(i);
            update(i);
            if (a <= m and m + 1 <= b)
                return get(a, b, l, m, (i << 1)) +
                       get(a, b, m + 1, r, (i << 1) + 1);
            else if (a <= m)
                return get(a, b, l, m, (i << 1));
            else if (m + 1 <= b)
                return get(a, b, m + 1, r, (i << 1) + 1);
        }
        return digit();
    }
    digit get(int a, int b) { return get(a, b, 0, n - 1, 1); }
    digit get(int a) { return get(a, a, 0, n - 1, 1); }

    void change(int* T, int i, int x) {
        int dx = x - T[i];
        T[i] = x;
        int val = get(i).val();
        if (val + dx >= 10) {
            // przekremci się w gure
            if (dx < 0) dx += 10;
            rotate(i, dx);
            digit res = get(i + 1, n - 1);
            int j = oo;
            for (int d = 0; d < 9; d++) {
                j = min(j, res.earliest(d));  // earliest non-9 on [i+1, n-1]
            }
            rotate(i + 1, j,
                   +1);  // add 1 on i+1, i+2, ... till the first non-9
        } else if (val + dx < 0) {
            // przekremci się w duł
            if (dx < 0) dx += 10;
            rotate(i, dx);
            digit res = get(i + 1, n - 1);
            int j = oo;
            for (int d = 1; d < 10; d++) {
                j = min(j, res.earliest(d));  // earliest non-0 on [i+1, n-1]
            }
            rotate(i + 1, j,
                   +9);  // subtract 1 on i+1, i+2, ... till the first non-0
        } else {
            if (dx < 0) dx += 10;
            rotate(i, dx);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    tree S = tree(n);
    string w, z;
    cin >> w >> z;
    for (int i = 0; i < n - 1; i++) {
        S.change(W, i, w[n - i - 2] - '0');
        S.change(Z, i, z[n - i - 2] - '0');
    }
    for (int qi = 0; qi < q; qi++) {
        char c;
        int i, x;
        cin >> c;
        if (c == 'S') {
            cin >> i;
            cout << S.get(i - 1).val() << "\n";
        }
        if (c == 'W') {
            cin >> i >> x;
            S.change(W, i - 1, x);
        }
        if (c == 'Z') {
            cin >> i >> x;
            S.change(Z, i - 1, x);
        }
    }
    return 0;
}

/*

5 6
7341
0150
S 3
W 3 0
S 3
Z 1 9
S 1
S 3

*/