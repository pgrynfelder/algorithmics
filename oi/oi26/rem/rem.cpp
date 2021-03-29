/*
REMONT
https://szkopul.edu.pl/problemset/problem/xNjwUvwdHQoQTFBrmyG8vD1O/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

int t, n, k;
vector<int> color, postorder, comp;
vector<bool> visited;
vector<vector<int>> g, gt;
map<pair<int, int>, vector<int>> bypattern;

void add(int a, int b) {
    g[a ^ 1].push_back(b);
    g[b ^ 1].push_back(a);

    gt[a].push_back(b ^ 1);
    gt[b].push_back(a ^ 1);
}

void reset() {
    int m = 2 * n + 7;
    bypattern.clear();
    color.resize(n + 1);
    g.clear();
    g.resize(m);
    gt.clear();
    gt.resize(m);
    postorder.clear();
    visited.assign(m, false);
    comp.assign(m, -1);
}

void dfs1(int a) {
    for (int b : g[a]) {
        if (!visited[b]) {
            visited[b] = true;
            dfs1(b);
        }
    }
    postorder.push_back(a);
}

void dfs2(int a) {
    for (int b : gt[a]) {
        if (comp[b] == -1) {
            comp[b] = comp[a];
            dfs2(b);
        }
    }
}

bool twosat() {
    for (int a = 2; a <= 2 * n + 1; a++) {
        if (!visited[a]) {
            visited[a] = true;
            dfs1(a);
        }
    }
    int i = 1;
    for (auto it = postorder.rbegin(); it != postorder.rend(); it++) {
        if (comp[*it] == -1) {
            comp[*it] = i++;
            dfs2(*it);
        }
    }
    for (int a = 2; a <= 2 * n + 1; a += 2) {
        if (comp[a] == comp[a + 1]) return false;
        // value[a / 2] = comp[a] > comp[a+1]
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        reset();

        cin >> color[1];
        for (int i = 2; i <= n; i++) {
            cin >> color[i];
            bypattern[{color[i - 1], color[i]}].push_back(i - 1);
        }

        // at least a one in each consecutive pair
        add(2 * 1, 2 * 1);
        for (int i = 1; i <= n - 2; i++) add(2 * i, 2 * (i + 1));
        add(2 * (n - 1), 2 * (n - 1));

        // at most one per pattern
        // for each pair (not a or not b)
        for (auto& [pattern, indices] : bypattern)
            for (auto it1 = indices.begin(); it1 != indices.end(); it1++)
                for (auto it2 = next(it1); it2 != indices.end(); it2++)
                    add(*it1 * 2 + 1, *it2 * 2 + 1);

        // for (int a = 2; a <= 2 * n - 1; a++) {
        //     cout << a << ": ";
        //     for (int b : g[a]) cout << b << " ";
        //     cout << "\n";
        // }

        cout << (twosat() ? "TAK\n" : "NIE\n");
    }

    return 0;
}

/*

2
4 3
2 3 2 3
7 3
2 2 2 3 2 3 1

*/