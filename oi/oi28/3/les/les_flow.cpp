// Piotr Grynfelder LES
#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/graph/min_cost_flow.html
struct Edge {
    int from, to, capacity, cost;
    Edge(int _from, int _to, int _capacity, int _cost) {
        from = _from, to = _to, capacity = _capacity, cost = _cost;
    }
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, const vector<Edge>& edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF) break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    // if (flow < K)
    //     return -1;
    // else
    cout << flow << endl;
    return cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> pre, cur;
    for (int q = 1; q <= n; q++) {
        int s;
        cin >> s;
        vector<Edge> edges;

        swap(pre, cur);
        cur.resize(s);
        for (int& a : cur) cin >> a;

        int A = pre.size(), B = cur.size();
        // A+B+1 for t, A+B for s
        if (q > 1) {
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < B; j++) {
                    edges.emplace_back(i, A + j, 1, abs(pre[i] - cur[j]));
                }
                edges.emplace_back(i, A + B + 1, 1, min(d - pre[i], pre[i]));
                edges.emplace_back(A + B, i, 1, 0);
            }
            for (int j = 0; j < B; j++) {
                edges.emplace_back(A + B, A + j, 1, min(d - cur[j], cur[j]));
                edges.emplace_back(A + j, A + B + 1, 1, 0);
            }
            cout << min_cost_flow(A + B + 2, edges, INF, A + B, A + B + 1) << "\n";
        }
    }

    return 0;
}