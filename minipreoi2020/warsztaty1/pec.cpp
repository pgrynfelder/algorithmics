// dp dynamik nt
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7, P = 13;

int dp[2][P];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    n = s.size();
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';

        for (int r = 0; r < P; r++) {
            dp[i & 1][(r * 10 + c) % P] = dp[(i + 1) & 1][r];
        }
        dp[i & 1][c]++;

        // cout << i << " " << c << ": ";
        // for (int j = 0; j < P; j++) {
        //     cout << dp[i & 1][j] << " ";
        // }
        // cout << "\n";

        res += dp[i & 1][0];
    }
    cout << res;
    return 0;
}