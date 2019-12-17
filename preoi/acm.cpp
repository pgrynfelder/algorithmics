#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
constexpr int inf = INT_MAX - 7;
int dp[4][N];
int t[4][N];
int k[7][4] = {{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {0, 3, 2, 1}};

int n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;	
	for (int i = 1; i <= n; i++){
		cin >> t[1][i];
	}
	for (int i = 1; i <= n; i++){
		cin >> t[2][i];
	}
	for (int i = 1; i <= n; i++){
		cin >> t[3][i];
	}
	int result = inf;
	for (int q = 0; q < 6; q++){
		int a = k[q][1], b = k[q][2], c = k[q][3];
		dp[a][0] = 0; dp[b][0] = dp[c][0] = dp[b][1] = dp[c][1] = dp[c][2] =  +inf;
		for (int i = 1; i <= n; i++){
			dp[a][i] = dp[a][i-1] + t[a][i];
			if (i > 1) dp[b][i] = min(dp[a][i-1], dp[b][i-1]) + t[b][i];
			if (i > 2) dp[c][i] = min(dp[b][i-1], dp[c][i-1]) + t[c][i];
		}
		result = min(result, dp[c][n]);
	}
	cout << result << "\n";
	return 0;
}
