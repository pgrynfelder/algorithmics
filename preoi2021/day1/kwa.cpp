#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e6 + 7;

vector<int> G[M];
bool visited[M];
int d[M];

void dfs(int a) {
    for (int b : G[a]) {
        if (!visited[b]) {
            visited[b] = 1;
            d[b] = d[a] + 1;
            dfs(b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> v; // height, diameter
        while (n--) {
            int m;
            cin >> m;

            for (int a = 1; a <= m; a++) {
                visited[a] = 0;
                G[a].clear();
            }

            int root;
            for (int a = 1; a <= m; a++) {

                int b;
                cin >> b;
                if (b == 0) {
                    root = a;
                } else {
                    G[b].push_back(a);
                    G[a].push_back(b);
                }
            }

            if (m == 1)
                continue;

            d[root] = 0;
            visited[root] = 1;
            dfs(root);
            int deepest;
            int height = -1;
            for (int a = 1; a <= m; a++) {
                if (d[a] > height) {
                    height = d[a];
                    deepest = a;
                }
                visited[a] = 0;
            }

            d[deepest] = 0;
            visited[deepest] = 1;
            dfs(deepest);
            int diameter = -1;
            for (int a = 1; a <= m; a++) {
                if (d[a] > diameter) {
                    diameter = d[a];
                }
            }

            v.emplace_back(height, diameter);
        }
        int sum = 0;
        for (auto &a : v) {
            sum += a.first * 2;
        }
        if (!v.empty()) {
            auto big = max_element(
                v.begin(), v.end(), [](const auto &a, const auto &b) {
                    return -a.first * 2 + a.second < -b.first * 2 + b.second;
                });
            auto smol = min_element(
                v.begin(), v.end(), [](const auto &a, const auto &b) {
                    return -a.first * 2 + a.second < -b.first * 2 + b.second;
                });
            cout << sum - 2 * big->first + big->second << " "
                 << sum - 2 * smol->first + smol->second << "\n";
        } else {
            cout << "0 0\n";
        }
    }

    return 0;
}

/*

2
3
5 0 1 2 1 4
3 2 0 2
2 2 0
2
1 0
1 0

*/