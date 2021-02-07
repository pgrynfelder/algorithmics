#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7, oo = 1e9 + 7;
vector<int> graph1[N], graph2[N];
set<pair<int, int>> graph3[N];
int degdown[N], dist[N];
int n, m;

bool visited[N];
vector<int> postorder;
void dfs1(int a) {
    for (int b : graph1[a]) {
        if (!visited[b]) {
            visited[b] = true;
            dfs1(b);
        }
    }
    postorder.emplace_back(a);
}

int comp[N];
void dfs2(int a) {
    for (int b : graph2[a]) {
        if (comp[b] == 0) {
            comp[b] = comp[a];
            dfs2(b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph1[a].emplace_back(b);
        graph2[b].emplace_back(a);
    }
    for (int a = 1; a <= n; a++) {
        if (!visited[a]) {
            visited[a] = true;
            dfs1(a);
        }
    }
    reverse(postorder.begin(), postorder.end());
    vector<int> components;
    for (int a : postorder) {
        if (comp[a] == 0) {
            comp[a] = a;
            components.emplace_back(a);
            dfs2(a);
        }
    }
    for (int a = 1; a <= n; a++) {
        for (int b : graph1[a]) {
            if (comp[a] != comp[b]) {
                graph3[comp[a]].emplace(comp[b], 0);  // original edge
                graph3[comp[b]].emplace(comp[a], 1);  // add edge up
                degdown[comp[a]]++;
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    for (int a : components) {
        visited[a] = false;
        dist[a] = oo;
        if (degdown[a] == 0) {
            dist[a] = 0;
            q.emplace(0, a);
        }
    }

    while (!q.empty()) {
        auto [d, a] = q.top();
        q.pop();

        if (visited[a]) continue;
        visited[a] = true;

        for (auto [b, w] : graph3[a]) {
            if (w + d < dist[b]) {
                dist[b] = w + d;
                q.emplace(dist[b], b);
            }
        }
    }
    int res = 0;
    for (int a = 1; a <= n; a++) {
        res = max(res, dist[comp[a]]);
    }
    cout << res + 1 << "\n";
    for (int a = 1; a <= n; a++) {
        cout << dist[comp[a]] << " ";
    }

    return 0;
}

/*
7 9
6 7
4 2
3 5
4 6
1 6
3 3
6 2
3 5
2 6

3
2 1 1 2 0 1 0
*/