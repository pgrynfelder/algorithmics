#include<bits/stdc++.h>
using namespace std;


// DP[meal 1 1][meal 1 2][meal 2 1][meal 2 2]
int DP1[3][3][3][3];
int DP2[3][3][3][3];

int different(int &a, int &b, int &c, int &i){
    int result = 0;
    if (a == 0 or b == 0 or c == 0) result++;
    if (a == 1 or b == 1 or c == 1) result++;
    if (a == 2 or b == 2 or c == 2) result++;
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> XD;
    XD['M'] = 0; XD['F'] = 1; XD['B'] = 2;
    for (int i = 0; i < s.size(); i++){
        int x = XD[s[i]];
        for (int a = 0; a < 3; a++){
            for (int b = 0; b < 3; b++){
                for (int c = 0; c < 3; c++){
                    for (int d = 0; d < 3; d++){
                        DP2[b][x][c][d] = max(DP2[b][x][c][d], DP1[a][b][c][d] + different(a, b, x, i));
                        DP2[a][b][d][x] = max(DP2[a][b][d][x], DP1[a][b][c][d] + different(c, d, x, i));
                    }
                }
            }
        }
        for (int a = 0; a < 3; a++){
            for (int b = 0; b < 3; b++){
                for (int c = 0; c < 3; c++){
                    for (int d = 0; d < 3; d++){
                        DP1[a][b][c][d] = DP2[a][b][c][d];
                    }
                }
            }
        }
    }

    int result = 0;
    for (int a = 0; a < 3; a++){
        for (int b = 0; b < 3; b++){
            for (int c = 0; c < 3; c++){
                for (int d = 0; d < 3; d++){
                    result = max(result, DP1[a][b][c][d]);
                }
            }
        }
    }
    cout << result-6 << '\n';
    return 0;
}

