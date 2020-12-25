#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3 + 7, M = 3E3 + 7;

struct edge {
    int i = 0, u = 0, v = 0, c = 0;
};
vector<edge> E;
vector<edge> in_tree;
int n, m;

int fu[N];
int fusize[N];

int f(int a) {
    if (fu[a] == a) {
        return a;
    }
    fu[a] = f(fu[a]);
    return fu[a];
}
void u(int a, int b) {
    a = f(a);
    b = f(b);
    if (fusize[b] > fusize[a]) { // keep a greater
        swap(a, b);
    }
    fusize[a] += fusize[b];
    fu[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        E.push_back({i, u, v, c});
    }
    sort(E.begin(), E.end(),
         [](const edge &a, const edge &b) { return a.c < b.c; });

    for (int v = 1; v <= n; v++) {
        fu[v] = v;
        fusize[v] = 1;
    }
    for (edge &e : E) {
        if (f(e.v) != f(e.u)) {
            u(e.v, e.u);
            in_tree.push_back(e);
        }
    }
    cout << in_tree[n / 2 - 1].c;
    return 0;
}

/*

4 6
1 2 1
1 3 2
1 4 3
2 3 4
2 4 5
3 4 6

*/