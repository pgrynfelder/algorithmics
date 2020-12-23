#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7;

unordered_set<int> G[N];
int degin[N];
int n, m;
queue<int> Q;
vector<int> S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << "NIE\n"; // nie istnieje
            return 0;
        }
        G[u].insert(v);
    }
    for (int u = 1; u <= n; u++) {
        for (int v : G[u]) {
            degin[v]++;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (degin[u] == 0)
            Q.push(u);
    }
    while (!Q.empty()) {
        if (Q.size() > 1) { // niejednoznaczne
            cout << "NIE\n";
            return 0;
        }
        int u = Q.front();
        Q.pop();
        S.push_back(u);
        for (int v : G[u]) {
            degin[v]--;
            if (degin[v] == 0) {
                Q.push(v);
            }
        }
    }
    if (S.size() != n) { // nie DAG
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n";
    for (int u : S) {
        cout << u << " ";
    }

    return 0;
}