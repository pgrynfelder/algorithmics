#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e4+7, S = 1e4+7;
int n, s = 1e4;
int t[N];
int d[N][S];
int lower = s, upper = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++){
        for (int j = lower; j <= upper; j++){ // from lower to upper
            d[i][j] = d[i-1][j];
        }
        if (t[i] > s) continue;
        d[i][t[i]] = i;
        int low = lower + t[i];
        int up = min(upper + t[i], s);
        for (int j = low; j <= up; j++){ // from (lower to upper) + t[i]
            if (d[i-1][j-t[i]] > d[i][j]){
                upper = max(upper, j);
                d[i][j] = d[i-1][j - t[i]];
            }
        }
        lower = min(lower, t[i]); upper = max(upper, max(t[i], s));

//        cout << "bounds: " << lower << " " << upper << "\n";
    }
//    for (int i = 1; i <= n; i++){
//        for (int j = 1; j <= s; j++){
//            cout << d[i][j] << " ";
//        }
//        cout << "\n";
//    }
    int q;
    cin >> q;
    while (q--){
        int a, b, x;
        cin >> a >> b >> x;
        cout << ((d[b][x] >= a) ? "TAK" : "NIE") << "\n";
    }
    return 0;
}
