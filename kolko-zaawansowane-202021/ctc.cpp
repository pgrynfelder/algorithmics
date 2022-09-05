/*
not working

centroid decomposition
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7;
// constexpr int N = 10;

vector<int> g[N];
long long s[N];  // size of subtree a
int n, k;
bool is_centroid[N];
long long res;

void dfs(int a, int p) {
    s[a] = 1;
    for (int b : g[a]) {
        if (!is_centroid[b] and b != p) {
            dfs(b, a);
            s[a] += s[b];
        }
    }
}

int depth[N];
void centroid_decomposition(int root, int d) {
    depth[root] = d;
    dfs(root, 0);

    int a = root, p = 0;
    bool has_big_child = true;
    while (has_big_child) {
        has_big_child = false;
        for (int b : g[a]) {
            if (!is_centroid[b] and b != p and s[b] * 2 > s[root]) {
                p = a;
                a = b;
                has_big_child = true;
                break;
            }
        }
    }

    is_centroid[a] = true;
    // run recursively
    for (int b : g[a])
        if (!is_centroid[b]) centroid_decomposition(b, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    centroid_decomposition(1, 0);

    for (int i = 1; i <= n; i++) cout << char('A' + depth[i]) << " ";

    return 0;
}