/*
ZJA
26 OI
https://szkopul.edu.pl/problemset/problem/bS_effBgQtuS7NXJA_dn7Ogm/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 250 + 7, MAXLOG_T = 16;
int n, m, k;

set<int> travelers;
vector<vector<bool>> binpaths[MAXLOG_T];

bool valid(vector<vector<bool>> &matrix) {
    for (int u = 1; u <= n; u++) {
        bool git = true;
        for (int t : travelers) {
            if (!matrix[t][u]) {
                git = false;
                break;
            }
        }
        if (git) return true;
    }
    return false;
}

vector<vector<bool>> join(vector<vector<bool>> &a, vector<vector<bool>> &b) {
    vector<vector<bool>> res(n + 1, vector<bool>(n + 1));
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            for (int w = 1; w <= n; w++)
                res[u][v] = res[u][v] or (a[u][w] and b[w][v]);
    return res;
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

    binpaths[0].resize(n + 1, vector<bool>(n + 1));
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
        binpaths[up + 1] = join(binpaths[up], binpaths[up]);
        up++;
    }
    if (up == MAXLOG_T - 1) {
        cout << "NIE";
        return 0;
    }

    vector<vector<bool>> cur(n + 1, vector<bool>(n + 1));
    int cur_t = 0;
    for (int u = 1; u <= n; u++) cur[u][u] = true;
    for (int i = up; i >= 0; i--) {
        auto neu = join(cur, binpaths[i]);
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