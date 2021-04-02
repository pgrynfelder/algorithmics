#include<bits/stdc++.h>
using namespace std;

int m;
int n;
const int inf = 10000;
vector<vector<int>> dp2;
vector<vector<int>> dp5;

int v5(int a){
    int res = 0;
    while (a % 5 == 0){
        a /= 5;
        res++;
    }
    return res;
}
int v2(int a){
    int res = 0;
    while (a % 2 == 0){
        a >>= 1;
        res++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    dp2 = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    dp5 = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    bool got0 = false;
    int a;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a;
            a = abs(a);
            
            if (a != 0){
                if (j > 1 and i > 1){
                    dp2[i][j] = min(dp2[i-1][j], dp2[i][j-1]) + v2(a);
                    dp5[i][j] = min(dp5[i-1][j], dp5[i][j-1]) + v5(a);
                } else if (j > 1) {
                    dp2[i][j] = dp2[i][j-1] + v2(a);
                    dp5[i][j] = dp5[i][j-1] + v5(a);
                } else if (i > 1) {
                    dp2[i][j] = dp2[i-1][j] + v2(a);
                    dp5[i][j] = dp5[i-1][j] + v5(a);
                } else {
                    dp2[i][j] = v2(a);
                    dp5[i][j] = v5(a);
                }
            } else {
                dp2[i][j] = inf;
                dp5[i][j] = inf;
                got0 = true;
            }
        }
    }
    if (got0){
        cout << min(1, min(dp2[n][m], dp5[n][m])) << "\n";
    } else {
        cout << min(dp2[n][m], dp5[n][m]) << "\n";
    }
    return 0;
}
