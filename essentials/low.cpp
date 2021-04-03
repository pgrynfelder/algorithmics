/*
dwuspójne składowe
low
bridges mosty
punkty artykulacji
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;

vector<int> g[N];
int dist[N], low[N];

bool visited[N];
void bridge(int a, int b);
void cutpoint(int a);
void dfs(int a, int p = -1) {
    low[a] = dist[a];
    for (int b : g[a]) {
        if (b == p) continue;

        low[a] = min(low[a], dist[b]);

        if (!visited[b]) {
            visited[b] = true;
            dist[b] = dist[a] + 1;
            dfs(b, a);
            low[a] = min(low[a], low[b]);
        }
        if (dist[a] < low[b]) bridge(a, b);
        if (dist[a] <= low[b] and p != -1) cutpoint(a);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}