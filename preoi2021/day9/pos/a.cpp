#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7;
// constexpr int N = 20;
int p[N], n;
long long t[N], s[N], sumt[N], E[N];
vector<pair<int, int>> graph[N];
vector<int> children[N];

void dfs1(int a) {
    sumt[a] = t[a];
    s[a] = 1;
    for (auto [b, tt] : graph[a]) {
        if (b != p[a]) {
            children[a].emplace_back(b);
            p[b] = a;
            t[b] = tt;
            dfs1(b);
            s[a] += s[b];
            sumt[a] += sumt[b];
        }
    }
}

void dfs2(int a) {
    E[a] = t[a] * s[a];
    for (int b : children[a]) {
        dfs2(b);
        E[a] += E[b];
    }
    sort(children[a].begin(), children[a].end(),
         [](int a, int b) { return sumt[a] * s[b] < sumt[b] * s[a]; });
    long long curr_t = 0;
    for (int b : children[a]) {
        E[a] += 2 * curr_t * s[b];
        curr_t += sumt[b];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, tt;
        cin >> a >> b >> tt;
        graph[a].emplace_back(b, tt);
        graph[b].emplace_back(a, tt);
    }
    dfs1(1);
    dfs2(1);
    cout << fixed << setprecision(6) << double(E[1]) / (n - 1);
    return 0;
}

/*
4
1 2 1
4 3 3
2 3 2

3.333333

4
1 2 1
1 3 1
1 4 1

3
*/