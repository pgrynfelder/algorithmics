#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 7, M = 3e5 + 7;
constexpr long long oo = 1e12 + 7;

set<int> graph[N];
long long weight[M], dist[M];
int target[M], n, m;
bool visited[M];
long long k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    srand(n * m % 107);
    vector<int> idx(m + 1);
    for (int i = 1; i <= m; i++) {
        idx[i] = i;
    }
    random_shuffle(++idx.begin(), idx.end());
    for (int i = 1; i <= m; i++) {
        int a;
        int j = idx[i];
        cin >> a >> target[j] >> weight[j];
        graph[a].emplace(j);
        dist[j] = oo;
    }
    target[0] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        q;
    q.emplace(0, 0);
    while (not q.empty()) {
        auto [d, e] = q.top();
        q.pop();
        if (target[e] == n) {
            cout << dist[e];
            return 0;
        }
        if (visited[e]) continue;
        visited[e] = true;

        for (auto it = graph[target[e]].begin();
             it != graph[target[e]].end();) {
            int e2 = *it;
            if ((weight[e] ^ weight[e2]) >= k) {
                dist[e2] = d + weight[e2];
                // key fact: dist is at edge end (target)

                q.emplace(dist[e2], e2);
                it = graph[target[e]].erase(it);
            } else {
                it++;
            }
        }
    }
    cout << -1;
    return 0;
}

/*
2 2 3
1 1 4
1 2 2

6


2 2 5
1 2 3
1 2 6

6


2 1 5
1 2 4

-1


4 4 0
1 2 1
2 4 2
1 3 2
3 4 0

2
*/