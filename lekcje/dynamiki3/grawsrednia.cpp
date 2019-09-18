#include<bits/stdc++.h>
using namespace std;

const int N = 1007;
int n;
double DP[N][N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> DP[i][i];
    }
    for (int l = 2; l <= n; l++){
        for (int i = 1; i + l - 1 <= n; i++){
            for (int j = i; j + 1 <= i + l - 1; j++){
                DP[i][i + l - 1] = max(DP[i][i + l -1], 0.5*(DP[i][j] + DP[j + 1][i + l - 1]));
            }
        }
    }
    cout << fixed << setprecision(6) << DP[1][n] << '\n';
	return 0;
}
