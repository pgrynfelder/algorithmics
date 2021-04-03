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
void dfs(int a, int p) {
    low[a] = dist[a];
    for (int b : g[a]) {
        if (b != p) {
            low[a] = min(low[a], dist[b]);
        }

        if (!visited[b]) {
            visited[b] = true;
            dist[b] = dist[a] + 1;
            dfs(b, a);
            low[a] = min(low[a], low[b]);
        }
    }
}

bool is_bridge(int a, int b){
    return dist[a] < low[b];
}

bool is_articulation_point(int a){
    if (a == 1 and g[a].size() > 1) return true;
    if (a != 1) for (int b : g[a]) if (dist[a] <= low[b]) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}