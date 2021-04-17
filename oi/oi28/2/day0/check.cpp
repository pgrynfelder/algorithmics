#include <bits/stdc++.h>
using namespace std;

constexpr int N = 107;

bool t[N][N];
long long dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    assert(n <= 100 and n >= 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            t[i][j] = (c == '.');
        }
    }
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (t[i][j] ? dp[i - 1][j] + dp[i][j - 1] : 0);

    cout << dp[n][n];
    return 0;
}