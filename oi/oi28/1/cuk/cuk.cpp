#include <bits/stdc++.h>
#define rest(n, i) t[n][0] + t[n][1] + t[n][2] - t[n][i]
using namespace std;

constexpr int K = 3, M = 1 << K;
constexpr int N = 3e5 + 7;
constexpr long long oo = 4 * N * 1e9;
long long dp[N][M];
long long t[N][3];
bool allZero[3] = {1, 1, 1};
unordered_set<int> potential_solutions = {M - 1};
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < K; k++) {
            cin >> t[i][k];
            if (t[i][k] > 0) {
                allZero[k] = 0;
            }
        }
    }

    for (int k = 0; k < K; k++) {
        if (allZero[k]) {
            unordered_set<int> toadd;
            for (int x : potential_solutions) {
                toadd.emplace(x & (~(1 << k)));
            }
            for (int x : toadd) {
                potential_solutions.emplace(x);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = oo;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < K; k++) {
                int mask = 1 << k;
                dp[i + 1][j | mask] =
                    min(dp[i + 1][j | mask], dp[i][j] + rest(i, k));
            }
        }
    }
    long long res = oo;
    for (int x : potential_solutions) {
        res = min(res, dp[n][x]);
    }
    cout << res << "\n";
    return 0;
}
