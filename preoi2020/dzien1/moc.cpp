// preprocessing
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3 + 7, Q = 1e5 + 7, A = 1e6 + 7;
int n, q;

vector<int> t;
long long dp[N][N];
vector<int> where[2 * A]; // offset by +A

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        where[t[i] + A].push_back(i);
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 1; l + i - 1 <= n; i++) {
            int j = l + i - 1;
            int rest = -(t[i] + t[j]);
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            if (abs(rest) < A)
                dp[i][j] += upper_bound(where[rest + A].begin(),
                                        where[rest + A].end(), j - 1) -
                            lower_bound(where[rest + A].begin(),
                                        where[rest + A].end(), i + 1);
        }
    }
    while (q-- > 0) {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }

    return 0;
}