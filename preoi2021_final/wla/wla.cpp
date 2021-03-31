/*
PREOI 2021 FINAL
WLA

O(n log n)
100

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;
constexpr long long oo = 1e9 + 7;

vector<long long> dp, m, pref;
int n;
long long M;

long long sum(int l, int r) { return pref[r] - pref[l - 1]; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--) {
        cin >> n >> M;
        m.assign(n + 2, 0);
        pref.assign(n + 2, 0);
        dp.assign(n + 2, 0);

        deque<pair<int, size_t>> Q;
        auto push = [&](int x, size_t i) {
            pair p(x, i);
            while(not Q.empty() and p < Q.front())
                Q.pop_front();
            Q.push_front(p);
        };
        auto pop = [&](size_t j) {
            while(not Q.empty() and Q.back().second > j)
                Q.pop_back();
        };

        for (int i = 1; i <= n; i++) {
            cin >> m[i];
            pref[i] = pref[i - 1] + m[i];
        }

        m[n + 1] = oo;
        pref[n + 1] = m[n + 1] + pref[n];

        multiset<int> current = {0};
        int limit = n;
        for (int i = n; i > 0; i--) {
            while (sum(i, limit) > M) {
                current.erase(current.find(dp[limit + 1]));
                limit--;
            }
            dp[i] = sum(i, n) - *current.begin();
            current.emplace(dp[i]);
        }

        cout << dp[1] << "\n";
    }
    return 0;
}

/*

1
5 3
1 2 1 2 1

1
5 1000
1 2 3 501 900

*/