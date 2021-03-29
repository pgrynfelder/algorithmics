/*
OI24
MID
https://szkopul.edu.pl/problemset/problem/wrTmzO9-dzEbLtsRUCdMV2_W/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;
int n, z, l[N], r[N], dist[N], last_dist;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    vector<int> start;

    int v = 1;
    while (v != 0) {
        start.emplace_back(v);
        v = l[v];
    }
    for (int v : start) l[v] = 0;

    queue<vector<int>> q;
    q.push(start);
    while (!q.empty()) {
        auto A = q.front();
        q.pop();

        vector<int> L, R;
        for (auto a : A) {
            dist[a] = last_dist;
            if (l[a]) L.push_back(l[a]);
            if (r[a]) R.push_back(r[a]);
        }
        last_dist++;
        if (!L.empty()) q.push(L);
        if (!R.empty()) q.push(R);
    }

    cin >> z;
    for (int i = 1; i <= z; i++) {
        int a, b;
        cin >> a >> b;
        cout << (dist[a] >= dist[b] ? "TAK" : "NIE") << "\n";
    }

    return 0;
}