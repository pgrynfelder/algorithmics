/*
26 OI
DLU
https://szkopul.edu.pl/problemset/problem/QHh99tBu4p9FMsFohv4da7S7/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, C= 250, oo = 1e7 + 7;

vector<int> G[N];
int n, m, p, c;
vector<int> vertices;
int d[C][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;
    c = min(C, n);

    unsigned seed = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        seed += a * b * (1 << i);
    }
    srand(seed);

    for (int i = 1; i <= n; i++) {
        vertices.emplace_back(i);
    }
    random_shuffle(vertices.begin(), vertices.end());

    for (int i = 0; i < c; i++) {
        for (int a = 1; a <= n; a++) d[i][a] = oo;
        d[i][vertices[i]] = 0;

        queue<int> q;
        q.emplace(vertices[i]);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int b : G[a]) {
                if (d[i][b] > d[i][a] + 1) {
                    d[i][b] = d[i][a] + 1;
                    q.emplace(b);
                }
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;
        int res = oo;
        for (int j = 0; j < c; j++) {
            res = min(res, d[j][a] + d[j][b]);
        }
        cout << res << "\n";
    }
    return 0;
}