#include <bits/stdc++.h>
using namespace std;

int n, k;
const int N = 2e5+7;

long long dp[2][N]; // 0 - not taken, 1 - could be taken
int used[2][N];
int numbers[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    cin >> numbers[i];
  }

  int r = 1e9, l = 0;
  int mid;
  while (l < r){
    mid = (l+r) / 2;
    for (int i = 1; i <= n; i++){
        dp[0][i] = dp[1][i] = dp[1][i-1];
        used[0][i] = used[1][i] = used[1][i-1];
        if (dp[0][i-1] + numbers[i] - mid > dp[1][i]){
            dp[1][i] = dp[0][i-1] + numbers[i] - mid;
            used[1][i] = used[0][i-1] + 1;
        }
    }
    if (used[1][n] <= k){
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  for (int i = 1; i <= n; i++){
    dp[0][i] = dp[1][i] = dp[1][i-1];
    if (dp[0][i-1] + numbers[i] - l > dp[1][i]){
        dp[1][i] = dp[0][i-1] + numbers[i] - l;
    }
  }
  cout << dp[1][n] + (long long)l*k << "\n";
} 
