#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7, LOGN = 18;

vector<int> graph[N];
int n, q, ptr[N][LOGN], dp[N][2], wheredp[N][2], dpup[N], depth[N];

void dfs(int a) {
    for (int i = 1; i < LOGN; i++) {
        ptr[a][i] = ptr[ptr[a][i - 1]][i - 1];
    }
    int wheremax = 0;
    for (int b : graph[a]) {
        if (b != ptr[a][0]) {
            ptr[b][0] = a;
            depth[b] = depth[a] + 1;
            dfs(b);
            if (dp[a][0] < dp[b][0] + 1) {
                dp[a][0] = dp[b][0] + 1;
                wheredp[a][0] = b;
            }
        }
    }
    for (int b : graph[a]) {
        if (b != ptr[a][0] and dp[a][1] < dp[b][0] + 1 and wheredp[a][0] != b) {
            dp[a][1] = dp[b][0] + 1;
            wheredp[a][1] = b;
        }
    }
}

void dfs2(int a) {
    for (int b : graph[a]) {
        if (b != ptr[a][0]) {
            dpup[b] = dpup[a] + 1;

            if (wheredp[a][0] != b) {
                // try to take best from a
                dpup[b] = max(dpup[b], dp[a][0] + 1);
            } else {
                // take the 2nd best
                dpup[b] = max(dpup[b], dp[a][1] + 1);
            }
            dfs2(b);
        }
    }
}

int lca(int a, int b) {
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[ptr[b][i]] >= depth[a]) b = ptr[b][i];
        if (depth[ptr[a][i]] >= depth[b]) a = ptr[a][i];
    }

    if (a == b) return a;

    for (int i = LOGN - 1; i >= 0; i--)
        if (ptr[a][i] != ptr[b][i]) a = ptr[a][i], b = ptr[b][i];

    return ptr[a][0];
}

int jump(int a, int h) {
    int target = depth[a] - h;
    for (int i = LOGN - 1; i >= 0; i--)
        if (depth[ptr[a][i]] >= target) a = ptr[a][i];
    return a;
}

int dist(int a, int b, int lowest_common_ancestor) {
    return depth[a] + depth[b] - (depth[lowest_common_ancestor] << 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    ptr[1][0] = 1;
    dfs(1);
    dfs2(1);
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << "0\n";
            continue;
        }
        int z = lca(x, y);
        int d = dist(x, y, z);
        if (depth[y] - ((d - 1) >> 1) > depth[z]) {
            // case 1: y below x (y can go up to just below lca)
            y = jump(y, (d - 1) >> 1);
            cout << dist(x, y, z) + dp[y][0] << "\n";
        } else {
            // case 2: y above x (y can exceed the lca)
            int below_y =
                jump(x,
                     ((d - 1) >> 1) +
                         (d & 1 ^ 1));  // for the sake of checking it later
            y = jump(below_y, 1);

            int res = dpup[y];
            if (wheredp[y][0] != below_y) {
                res = max(res, dp[y][0]);
            } else {
                res = max(res, dp[y][1]);
            }
            cout << res + depth[x] - depth[y] << "\n";
        }
    }

    return 0;
}

/*
11
1 2
2 3
2 4
2 5
4 6
6 9
6 10
5 7
5 8
8 11
10
2 6
11 2
9 3
6 11
11 9
3 11
9 10
1 2
2 1
2 2

3
6
6
5
6
4
2
4
1
0


8
1 2
8 3
2 6
2 8
7 2
5 3
4 1
1
2 1

1
*/