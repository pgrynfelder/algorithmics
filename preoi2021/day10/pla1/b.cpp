// zamiatanie sweeping segseg drzewo (lepiej było użyć seta i na pałę matchować
// wysokość, moje dostało 81)

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, oo = 1e9 + 7;
int n, q, H;
int l[N], r[N], h[N];

int X;
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

struct platform {
    int l, r, h, i;
    bool operator<(const platform &other) const {
        return r < other.r or (r == other.r and l < other.l);
    }
};

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
    }

    vector<int> platforms;
    for (int i = 1; i <= n; i++) {
        platforms.emplace_back(i);
        fu[i] = i;
    }

    sort(platforms.begin(), platforms.end(),
         [](const int a, const int b) { return h[a] < h[b]; });

    set<platform> s;  // keep separate ranges
    for (int i : platforms) {
        for (auto it =
                 s.lower_bound({0, l[i], 0, 0});  // find 1st with r >= l[i]
             it != s.end() and it->l <= r[i]; it = s.erase(it)) {
            if (it->h + H >= h[i]) {
                u(it->i, i);
                if (it->l < l[i]) s.insert({it->l, l[i] - 1, it->h, it->i});
                if (it->r > r[i]) s.insert({r[i] + 1, it->r, it->h, it->i});
            }
        }
        s.insert({l[i], r[i], h[i], i});
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