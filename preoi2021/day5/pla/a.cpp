#include <bits/stdc++.h>
using namespace std;

constexpr int N = 107, oo = 1e9 + 7;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) dp[i][j] = oo;

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
            dp[j][i] = dp[i][j];
        }
    }
    cout << dp[n][m];
    return 0;
}