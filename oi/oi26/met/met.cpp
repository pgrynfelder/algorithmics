/*
METRO
https://szkopul.edu.pl/problemset/problem/hxMnCQMERV9OY1QwAdEXxQFy/site/?key=statement

Piotr Grynfelder
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e6 + 7;
int n, k;
vector<int> G[N], sol[N];
int deg[N], d[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    for (int a = 1; a <= n; a++) {
        if (deg[a] == 1) sol[0].push_back(a);
    }
    int maxi;
    for (int i = 0; i <= n; i++) {
        if (sol[i].empty()) {
            maxi = i - 1;
            break;
        }
        for (int a : sol[i]) {
            for (int b : G[a]) {
                deg[b]--;
                if (deg[b] == 1) {
                    sol[i + 1].push_back(b);
                }
            }
        }
    }
    // for (int a = 1; a <= n; a++) assert deg[a] == 0;

    for (int i = 0; i <= maxi; i++) {
        if (sol[i].size() <= k) {
            if (sol[i].size() != 1) {
                cout << i << " " << sol[i].size() << "\n";
                for (int a : sol[i]) cout << a << " ";
            } else {
                cout << i << " " << 2 << "\n";
                cout << sol[i][0] << " " << G[sol[i][0]][0];
            }
            return 0;
        }
    }
    return 0;
}

/*

8 3
1 2
2 3
2 4
4 5
5 6
5 7
5 8


*/