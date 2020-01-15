#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+7;
constexpr long long M = 1e9 + 7;

// A(i): i; B(i): i v (i + 1); 
long long dp[3][N]; // taken A(i); taken B(i-1); taken B(i)
long long A[N], B[N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> A[i];
	}
	for (int i = 1; i < n; i++){
		cin >> B[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++){
		dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) * A[i] % M;
		dp[1][i] = ((dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) * B[i-1] - dp[2][i-1]) % M;
		dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) * B[i] % M;
	}
	
	
	cout << (dp[0][n] + dp[1][n] + dp[2][n])%M << "\n";
						
	return 0;
}
