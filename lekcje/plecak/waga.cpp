#include<bits/stdc++.h>
using namespace std;

const int N = 50+7;
//const int N = 10;
int n, l, p;
const int C = N*N*N;
const int inf = C + 7;
int dp[2][2*C + 7];
int towers[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> p;
    int rng = n * (l+p) * N;
    
    int sum = 0;
    for (int j = 1; j <= l; j++){
        for (int i = 0; i < n; i++){
            cin >> towers[j][n - i];
            sum += towers[j][n - i];
        }
    }
    for (int j = l + 1; j <= l + p; j++){
        for (int i = 0; i < n; i++){
            cin >> towers[j][n - i];
            towers[j][n - i] *= -1;
            sum += towers[j][n - i];
        }
    }
    for (int i = C - rng; i < C + rng; i++){
        dp[0][i] = inf; dp[1][i] = inf;
    }
    dp[0][C + sum] = 0;
    dp[1][C + sum] = 0;
    int global_min = inf;
    int left = C + sum, right = C + sum;
    for (int j = 1; j <= l + p; j++){
        int prefix = 0;
        for (int i = 1; i <= n; i++){
            prefix += towers[j][i];
            for (int k = left - prefix; k <= right - prefix; k++){
                dp[j & 1][k] = min(dp[j & 1][k], dp[(j + 1) & 1][k]);
                if (dp[j & 1][k] > dp[(j + 1) & 1][k + prefix] + i){
                    dp[j & 1][k] = dp[(j + 1) & 1][k + prefix] + i;
                    left = min(left, k);
                    right = max(right, k);
                }
            }
        }
        global_min = min(global_min, min(dp[(j + 1) & 1][C], dp[j & 1][C]));
    }
    cout << global_min << "\n";
    return 0;
}
