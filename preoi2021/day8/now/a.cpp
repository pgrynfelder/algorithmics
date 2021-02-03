// parametric search
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<ll> d, t;
pair<ll, ll> dp[2][2];

void solve(ll x) {  // x - encouragment modifier
    dp[1][0] = dp[1][1] = {0, 0};
    for (int i = 2; i <= n; i++) {
        dp[i & 1][1] = dp[i & 1][0] = min(dp[i & 1 ^ 1][0], dp[i & 1 ^ 1][1]);
        if (dp[i & 1 ^ 1][0].first + d[i] - d[i - 1] - x < dp[i & 1][1].first) {
            dp[i & 1][1] = {dp[i & 1 ^ 1][0].first + d[i] - d[i - 1] - x,
                            dp[i & 1 ^ 1][0].second + 1};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        cin >> n >> k;
        d.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        ll l = -1e9, r = 1e9, m;
        while (l < r) {
            m = l + (r - l) / 2;
            solve(m);
            auto [cost, cnt] = dp[n & 1][1];
            if (cnt > k) {  // za dużo -> mniej zachęcać
                r = m;
            } else {
                l = m + 1;
            }
        }
        solve(l - 1);
        auto [cost, cnt] = dp[n & 1][1];
        // * k <- ważne bardzo
        cout << cost + (l - 1) * k << "\n";
    }

    return 0;
}

/*
3
5 1
1 3 6 10 15
5 2
1 3 6 10 15
6 2
1 5 7 11 14 17

2
6
5
*/