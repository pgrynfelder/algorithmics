#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll inf = 1e16+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> A(n+1, vector<ll>(m+1, -inf));
    A[0][1] = 0;
    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= m; i++){
            cin >> A[j][i];
            A[j][i] += max(A[j-1][i], A[j][i-1]);
        }
    }
    cout << A[n][m] << '\n';
    return 0;
}