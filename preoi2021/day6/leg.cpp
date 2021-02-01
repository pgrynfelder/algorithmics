#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 7;
constexpr long long oo = (2e5 + 7) * (1e9 + 7);

int l[N], r[N];
long long c[N], d[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> l[i];
        for (int i = 1; i <= n; i++)
            cin >> r[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= n; i++) {
            d[i] = oo;
        }
        set<int> left;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;

        for (int i = 2; i <= n; i++) {
            left.emplace(i);
        }
        q.emplace(c[1], 1);
        d[1] = 0;
        while (!q.empty()) {
            auto [dist, a] = q.top();
            q.pop();
            // lhs
            auto it = left.lower_bound(a - r[a]);
            while (it != left.end() and *it <= a - l[a]) {
                d[*it] = dist;
                q.emplace(dist + c[*it], *it);
                it = left.erase(it);
            }
            // rhs
            it = left.lower_bound(a + l[a]);
            while (it != left.end() and *it <= a + r[a]) {
                d[*it] = dist;
                q.emplace(dist + c[*it], *it);
                it = left.erase(it);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << (d[i] != oo ? d[i] : -1) << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*

3
3
1 1 1
1 1 1
1 1 1
2
0 1
0 1
1 1
5
2 0 0 0 1
3 1 1 0 5
1 1 1 1 1

*/