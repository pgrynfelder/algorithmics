/*
Paths in a tree
Ścieżki w drzewie

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

long long cnt[N];
void dfs_add(int a, int p, int d) {
    if (d > k) return;
    cnt[d]++;

    for (int b : g[a]) {
        if (!is_centroid[b] and b != p) {
            dfs_add(b, a, d + 1);
        }
    }
}

void dfs_remove(int a, int p, int d) {
    if (d > k) return;
    cnt[d]--;

    for (int b : g[a]) {
        if (!is_centroid[b] and b != p) {
            dfs_remove(b, a, d + 1);
        }
    }
}

void dfs_count(int a, int p, int d) {
    if (d > k) return;
    res += cnt[k - d];
    if (d == k) res++;  // all but these are counted twice

    for (int b : g[a]) {
        if (!is_centroid[b] and b != p) {
            dfs_count(b, a, d + 1);
        }
    }
}

void centroid_decomposition(int root) {
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

    dfs_add(a, 0, 0);
    for (int b : g[a]) {
        if (!is_centroid[b]) {
            dfs_remove(b, a, 1);
            dfs_count(b, a, 1);
            dfs_add(b, a, 1);
        }
    }
    dfs_remove(a, 0, 0);

    is_centroid[a] = true;
    // run recursively
    for (int b : g[a])
        if (!is_centroid[b]) centroid_decomposition(b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    centroid_decomposition(1);

    cout << res / 2;

    return 0;
}