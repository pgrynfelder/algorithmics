/*
ZJA
26 OI
https://szkopul.edu.pl/problemset/problem/bS_effBgQtuS7NXJA_dn7Ogm/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 250 + 7, MAXLOG_T = 20;
int n, m, k;

set<int> travelers;

/*
w/ binary matrix multiplication on bitset
*/
struct M {
    int h, w;
    bitset<N> m[N];
    M() {}
    M(int _h, int _w) {
        h = _h, w = _w;
        for (int i = 0; i < w; i++) m[i] = 0;
    }
    
    bitset<N> &operator[](size_t i) { return m[i]; }

    M operator*(M &other) {
        M res(h, other.w);
        for (int j = 0; j < res.h; j++) {
            bitset<N> cur = 0;
            for (int i = 0; i < w; i++)
                if (m[i][j]) cur[i] = 1;

            for (int i = 0; i < res.w; i++)
                if ((cur & other[i]).any()) res[i][j] = 1;
        }
        return res;
    }
};

M binpaths[MAXLOG_T];

bool valid(M &matrix) {
    for (int u = 1; u <= n; u++) {
        bool git = true;
        for (int t : travelers) {
            if (matrix[t][u] == 0) {
                git = false;
                break;
            }
        }
        if (git) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++) {
        int t;
        cin >> t;
        travelers.emplace(t);
    }

    binpaths[0] = M(n + 1, n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        binpaths[0][u][v] = true;
    }
    if (travelers.size() <= 1) {
        cout << "TAK\n0";
        return 0;
    }

    int up = 0;
    while (up < MAXLOG_T - 1 and !valid(binpaths[up])) {
        binpaths[up + 1] = binpaths[up] * binpaths[up];
        up++;
    }

    if (up == MAXLOG_T - 1) {
        cout << "NIE";
        return 0;
    }

    M cur(n + 1, n + 1);
    int cur_t = 0;
    for (int u = 1; u <= n; u++) cur[u][u] = 1;

    for (int i = up; i >= 0; i--) {
        auto neu = binpaths[i] * cur;
        if (!valid(neu)) {
            cur = neu;
            cur_t += (1 << i);
        }
    }
    cout << "TAK\n" << cur_t + 1;
    return 0;
}

/*

5 7 3
1 2 3
1 2
1 3
2 3
3 4
4 1
4 5
5 1

*/