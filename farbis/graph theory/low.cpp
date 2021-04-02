// #low #bridge #bridges #most

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;

vector<int> G[N];
int d[N];
int low[N];
int visited[N];
int p[N];

void dfs(int v) {
    low[v] = d[v];
    for (int u : G[v]) {
        if (!visited[u]) { // is child
            d[u] = d[v] + 1;
            p[u] = v;
            dfs(u);
            low[v] = min(low[v], low[u]);
        } else if (u != p[v]) { // is back edge
            low[v] = min(low[v], low[u]);
        }
    }
}

bool bridge(int v, int u) { // edge v -> u
    return d[v] < low[u];
}

bool articulation(int v) {
    for (int u : G[v]) {
        if (u != p[v]){
            if (d[v] <= low[u]){
                return true;
            }
        }
    }
    return false;
}