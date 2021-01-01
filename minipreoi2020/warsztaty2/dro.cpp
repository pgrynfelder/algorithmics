// silnie spojne, ssc, strongly connected components
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e4 + 7, M = 1e5 + 7;

int n, m;
vector<int> g[N];
vector<int> gt[N];

bool visited[N];
vector<int> po;
void dfs1(int a) {
    for (int b : g[a]) {
        if (!visited[b]) {
            visited[b] = 1;
            dfs1(b);
        }
    }
    po.push_back(a);
}

int comp[N];
int compsize[N];
void dfs2(int a) {
    for (int b : gt[a]) {
        if (comp[b] == 0) {
            comp[b] = comp[a];
            compsize[comp[b]]++;
            dfs2(b);
        }
    }
}

unordered_set<int> dag[N];
bool dagvisited[N];
int dp[N];
void dfs3(int a) {
    dp[a] = compsize[a];
    for (int b : dag[a]) {
        if (!dagvisited[b]) {
            dagvisited[b] = 1;
            dfs3(b);
        }
        dp[a] += dp[b];
    }
    // cout << "comp " << a << ": " << dp[a] << "\n";
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
        gt[b].emplace_back(a);
    }
    for (int a = 1; a <= n; a++) {
        if (!visited[a]) {
            visited[a] = 1;
            dfs1(a);
        }
    }
    for (auto it = po.rbegin(); it != po.rend(); it++) {
        int a = *it;
        if (comp[a] == 0) {
            comp[a] = a;
            compsize[a]++;
            dfs2(a);
        }
    }

    // for (int a = 1; a <= n; a++) {
    //     cout << a << ": " << comp[a] << " " << compsize[comp[a]] << "\n";
    // }

    for (int a = 1; a <= n; a++) {
        for (int b : g[a]) {
            if (comp[a] != comp[b]) {
                dag[comp[a]].insert(comp[b]);
            }
        }
    }

    for (int a = 1; a <= n; a++) {
        if (!dagvisited[comp[a]]) {
            dagvisited[comp[a]] = 1;
            dfs3(comp[a]);
        }
        cout << dp[comp[a]] - 1 << "\n";
    }

    return 0;
}