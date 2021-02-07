#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
constexpr long long oo = 1e16 + 7;
int n, m;
vector<pair<int, int>> graph[2 * N];
long long dist[2 * N];
bool visited[2 * N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        if (w & 1) {
            graph[a].emplace_back(b + N, w);
            graph[b + N].emplace_back(a, w);

            graph[b].emplace_back(a + N, w);
            graph[a + N].emplace_back(b, w);
        } else {
            graph[a].emplace_back(b, w);
            graph[b].emplace_back(a, w);

            graph[a + N].emplace_back(b + N, w);
            graph[b + N].emplace_back(a + N, w);
        }
    }

    for (int i = 2; i < 2 * N; i++) dist[i] = oo;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        q;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [d, a] = q.top();
        q.pop();
        if (visited[a]) continue;
        visited[a] = true;

        for (auto [b, w] : graph[a]) {
            if (d + w < dist[b]) {
                dist[b] = d + w;
                q.emplace(dist[b], b);
            }
        }
    }

    long long res = -oo;
    for (int a = 1; a <= n; a++)
        if (dist[a] != oo and dist[a + N] != oo)
            res = max(res, dist[a] + dist[a + N]);

    for (int a = 1; a <= n; a++)
        if (dist[a] + dist[a + N] == res) cout << a << "\n";
    if (res == -oo)
        cout << "BRAK";
    else
        cout << res;
    return 0;
}