#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7;
constexpr long long inf = 1e18;

int n;
vector<int> X;
vector<long long> dp[2]; 
// 0 don't take 
// 1 take

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n;
	X.resize(n);
	dp[0].resize(n+1);
	dp[1].resize(n+1);
	for (int i = 0; i < n; i++) cin >> X[i];
	sort(X.begin(), X.end());
	reverse(X.begin(), X.end());
	long long result = 0;
	for (int a : X) result += a;
	dp[0][1] = 0;
	dp[1][1] = inf;
	for (int i = 2; i <= n; i++){
		dp[0][i] = min(dp[0][i-1], dp[1][i-1]);
		dp[1][i] = dp[0][i-1] + X[i-1];
	}
	cout << result - min(dp[0][n], dp[1][n]);
	return 0;
}

/*

5
1 2 3 -10 -1000

*/
