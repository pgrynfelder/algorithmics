#include<bits/stdc++.h>
using namespace std;
const int N = 57;
const int inf = 1e6;
int n, m;

int G[N][2*N];
int DP[2*N][N][N][N]; // n+m - 1; a; b; c

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&G[0][0], &G[N-1][2*N-1], -inf);
    cin >> n >> m;
    for (int j = 1; j <= n; j++){
        string s;
        cin >> s;
        for (int i = 1; i <= m; i++){
            int v = s[i-1] - '0';
            G[i][i + j - 1] = v;
        }
    }

    // for (int y = 1; y <= n + m - 1; y++){
    //     for (int x = 1; x <= m; x++){
    //         cout << G[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int y = 1; y <= n + m - 1; y++){
        for (int a = 1; a <= m; a++){
            for (int b = 1; b <= m; b++){
                for (int c = 1; c <= m; c++){
                    for (int mask = 0; mask < 8; mask++){
                        int newdp = DP[y-1][a - (bool)(mask & 1)][b - (bool)(mask & 2)][c - (bool)(mask & 4)];
                        newdp += G[a][y];
                        if (a != b){
                            newdp += G[b][y];
                        }
                        if (c != a and c != b){
                            newdp += G[c][y];
                        }
                        DP[y][a][b][c] = max(DP[y][a][b][c], newdp);
                    }
                }
            }
        }
    }
    cout << DP[n + m - 1][m][m][m] << '\n';

    return 0;
}
