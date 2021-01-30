// turbomatching
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;

vector<int> G[N];
int match[N];
bool visited[N];
int n;

bool augment(int u) {
    visited[u] = 1;
    for (int v : G[u]) {
        if (match[v] == -1) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    for (int v : G[u]) {
        if (not visited[match[v]] and augment(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int a = 1; a <= n; a++) {
        match[a] = -1;
    }
    while (true) {
        for (int u = 0; u < n; u++)
            visited[u] = 0;
        bool any = false;
        for (int u = 0; u < n; u++)
            if (match[u] == -1 and augment(u))
                any = true;
        if (not any)
            break;
    }
    return 0;
}