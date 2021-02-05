#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7;
int n, q, H;
int l[N], r[N], h[N];

map<int, int> scale;
int X;

constexpr pair<int, int> def = {-1, 0};
template <typename T>
struct segsegtree {
    int n = 1;
    vector<T> t;
    vector<bool> star;
    segsegtree(int _n) {
        while (n < _n) {
            n *= 2;
        }
        t.assign(2 * n, def);
        star.resize(2 * n, false);
    }
    void propagate(int i) {
        if (star[i]) {
            t[2 * i] = t[2 * i + 1] = t[i];
            star[2 * i] = star[2 * i + 1] = true;
            star[i] = false;
        }
    }
    void update(int i) { t[i] = max(t[2 * i], t[2 * i + 1]); }

    int a, b;
    T x;
    T _read(int l, int r, int i) {
        if (a <= l and r <= b) {
            return t[i];
        }
        int m = l + r >> 1;
        T result = def;
        propagate(i);
        if (a <= m) result = max(result, _read(l, m, 2 * i));
        if (m < b) result = max(result, _read(m + 1, r, 2 * i + 1));
        return result;
    }
    T read(int _a, int _b) {
        a = _a, b = _b;
        return _read(0, n - 1, 1);
    }
    void _insert(int l, int r, int i) {
        if (a <= l and r <= b) {
            t[i] = x;
            star[i] = true;
            return;
        }
        int m = l + r >> 1;
        propagate(i);
        if (a <= m) _insert(l, m, 2 * i);
        if (m < b) _insert(m + 1, r, 2 * i + 1);
        update(i);
    }
    void insert(int _a, int _b, T _x) {
        a = _a, b = _b, x = _x;
        if (a > b) return;
        _insert(0, n - 1, 1);
    }
};

int fu[N], furank[N];
int f(int a) {
    if (fu[a] == a) {
        return a;
    }
    fu[a] = f(fu[a]);
    return fu[a];
}
void u(int a, int b) {
    a = f(a), b = f(b);
    if (a == b) return;

    if (furank[a] < furank[b])
        swap(a, b);
    else if (furank[a] == furank[b])
        furank[a]++;
    fu[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q >> H;
    for (int i = 1; i <= n; i++) {
        int x, y, len;
        cin >> x >> y >> len;
        l[i] = x;
        r[i] = x + len - 1;
        h[i] = y;
        scale[l[i]] = scale[r[i]] = 0;
    }
    for (auto it = ++scale.begin(); it != scale.end(); it++) {
        it->second = prev(it)->second + 1;
    }
    X = scale.size();

    vector<int> platforms;
    for (int i = 1; i <= n; i++) {
        l[i] = scale[l[i]];
        r[i] = scale[r[i]];
        platforms.emplace_back(i);
        fu[i] = i;
    }

    sort(platforms.begin(), platforms.end(),
         [](const int a, const int b) { return h[a] < h[b]; });

    segsegtree<pair<int, int>> t(X);

    for (int a : platforms) {
        auto xd = t.read(l[a], r[a]);
        auto val = xd.first, b = xd.second;
        while (val >= h[a]) {
            u(a, b);
            t.insert(max(l[a], l[b]), min(r[a], r[b]), {0, 0});
            xd = t.read(l[a], r[a]);
            val = xd.first, b = xd.second;
        }
        t.insert(l[a], r[a], {h[a] + H, a});
    }

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (f(a) == f(b) ? "YES\n" : "NO\n");
    }

    return 0;
}

/*
3 2 3
2 7 3
4 4 2
0 1 4
1 2
3 2

YES
NO
*/