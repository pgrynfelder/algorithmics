
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;

template <typename T> struct Tree {
    vector<T> t;
    vector<T> prop;
    int n = 1;
    Tree(int _n) {
        while (n < _n) {
            n <<= 1;
        }
        t.resize(n << 1);
        prop.resize(n << 1);
    }

    T read(int a, int b, int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }

        int mid = (l + r) / 2;
        T result = 0;
        if (a <= mid or b >= mid + 1) {
            // propagation
            t[i << 1] += prop[i] / 2;
            t[(i << 1) + 1] += prop[i] / 2;
            prop[i << 1] += prop[i] / 2;
            prop[(i << 1) + 1] += prop[i] / 2;
            prop[i] = 0;

            if (a <= mid) {
                result += read(a, b, l, mid, (i << 1));
            }
            if (b >= mid + 1) {
                result += read(a, b, mid + 1, r, (i << 1) + 1);
            }
        }
        return result;
    }

    T read(int a, int b) { return read(a, b, 0, n - 1, 1); }

    void add(int a, int b, int l, int r, int i, T x) {
        if (a <= l and r <= b) {
            t[i] += x * (r - l + 1);
            prop[i] += x * (r - l + 1);
            return;
        }
        int mid = (l + r) / 2;
        if (a <= mid or b >= mid + 1) {
            // propagation
            t[i << 1] += prop[i] / 2;
            t[(i << 1) + 1] += prop[i] / 2;
            prop[i << 1] += prop[i] / 2;
            prop[(i << 1) + 1] += prop[i] / 2;
            prop[i] = 0;

            if (a <= mid) {
                add(a, b, l, mid, (i << 1), x);
            }
            if (b >= mid + 1) {
                add(a, b, mid + 1, r, (i << 1) + 1, x);
            }
            t[i] = t[i << 1] + t[(i << 1) + 1];
        }
    }

    void add(int a, int b, T x) { add(a, b, 0, n - 1, 1, x); }

    void print() {
        int m = 1;
        for (int i = 1; i < (n << 1); i++) {
            if (i == m) {
                m <<= 1;
                cout << "\n";
            }
            cout << t[i] << ":" << prop[i] << "  ";
        }
        cout << "\n";
    }
};

int n;

int main() {
    cin >> n;
    Tree<long long> tree(n);
    while (true) {
        char c;
        cin >> c;
        if (c == '=') {
            int a, b;
            cin >> a >> b;
            cout << tree.read(a - 1, b - 1) << "\n";
        } else if (c == '+') {
            int a, b, x;
            cin >> a >> b >> x;
            tree.add(a - 1, b - 1, x);
            tree.print();
        }
    }
    return 0;
}
