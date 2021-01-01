// bfs
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, M = 1e5 + 7;

int n, m;
vector<int> G[N + M];
queue<int> q;
int dist[N + M];
bool visited[N + M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int a = 1 + N; a <= m + N; a++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int b;
            cin >> b;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }
    }

    visited[1] = 1;
    q.emplace(1);
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int b : G[a]) {
            if (!visited[b]) {
                visited[b] = 1;
                dist[b] = dist[a] + 1;
                q.emplace(b);
            }
        }
    }
    cout << dist[n] / 2;

    return 0;
}