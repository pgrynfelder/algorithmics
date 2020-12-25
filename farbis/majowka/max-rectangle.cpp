#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> p;
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (m <= n){
        p.resize(m+1, vector<long long>(n+1));
        for (int y = 1; y <= n; y++){
            for (int x = 1; x <= m; x++){
                cin >> p[x][y];
                p[x][y] = p[x][y] + p[x-1][y] + p[x][y-1] - p[x-1][y-1];
            }
        }
    }
    else {
        p.resize(n+1, vector<long long>(m+1));
        for (int y = 1; y <= n; y++){
            for (int x = 1; x <= m; x++){
                cin >> p[y][x];
                p[y][x] = p[y][x] + p[y-1][x] + p[y][x-1] - p[y-1][x-1];
            }
        }
        swap(n, m);
    }

    // [l, r] in terms of X
    long long res = 0;
    for (int l = 1; l <= m; l++){
        for (int r = l; r <= m; r++){
            long long current = 0, lowest = 0;
            for (int y = 1; y <= n; y++){
                current += p[r][y] - p[l-1][y] - p[r][y-1] + p[l-1][y-1];
                lowest = min(lowest, current);
                res = max(res, current - lowest);
            }
        }
    }
    cout << res;
    return 0;
}
 
/*

3 5
-1 2 0 -2 1
2 1 0 -4 -3
-1 2 -3 1 4

3 5
8 4 -2 -7 -8
1 0 -8 4 -9
1 5 3 1 -1
*/