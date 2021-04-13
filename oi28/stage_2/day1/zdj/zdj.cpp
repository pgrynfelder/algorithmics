#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;

int n, m;
vector<int> g[N], g2[N];
vector<pair<int, int>> e;
int deg[N];

vector<int> postorder;
bool visited[N];
void dfs(int a) {
    for (int b : g2[a]) {
        if (!visited[b]) {
            visited[b] = true;
            dfs(b);
        }
    }
    postorder.push_back(a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        e.emplace_back(a, b);
        deg[a]++;
        deg[b]++;
    }
    if (n <= 10) {
        vector<int> hat;
        hat.resize(n + 1);
        for (int i = 1; i <= n; i++) hat[i] = i;
        do {
            bool valid = true;
            for (int a = 3; a <= n; a++) {
                int cnt = 0;
                for (int b : g[a])
                    if (hat[b] > hat[a]) cnt++;
                if (cnt != g[a].size() / 2) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << "TAK\n";
                for (int a = 1; a <= n; a++) {
                    cout << hat[a] << " ";
                }
                return 0;
            }
        } while (next_permutation(next(hat.begin()), hat.end()));
    } else if (m <= 20) {
        vector<int> vertices;
        for (int a = 1; a <= n; a++)
            if (deg[a]) vertices.emplace_back(a);
        for (int mask = 0; mask < (1 << m); mask++) {
            for (int i = 0; i < m; i++) {
                auto [a, b] = e[i];
                if ((mask >> i) & 1) {
                    g2[a].emplace_back(b);
                } else {
                    g2[b].emplace_back(a);
                }
            }
            for (int a : vertices) {
                if (!visited[a]) {
                    visited[a] = 1;
                    dfs(a);
                }
            }
            vector<int> hat(n + 1);
            int i = 1;
            for (int a : postorder) {
                hat[a] = i;
                i++;
            }
            bool valid = true;
            for (int a : vertices) {
                if (a > 2) {
                    int cnt = 0;
                    for (int b : g2[a])
                        if (hat[b] > hat[a]) cnt++;
                    if (cnt != g2[a].size() / 2) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
                cout << "TAK\n";
                int j = vertices.size() + 1;
                for (int a = 1; a <= n; a++) {
                    if (hat[a] != 0) {
                        cout << hat[a] << " ";
                    } else {
                        cout << j << " ";
                        j++;
                    }
                }
                return 0;
            }

            for (int a : vertices) {
                g2[a].clear();
                visited[a] = false;
                hat[a] = 0;
            }
            postorder.clear();
        }
    }
    cout << "NIE";
    return 0;
}