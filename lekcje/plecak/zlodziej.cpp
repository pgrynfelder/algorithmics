#include<bits/stdc++.h>
using namespace std;

int value[1007];
int weight[1007];

int DP1[1007][10007];
int DP2[1007][10007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, B;
    cin >> n >> B;
    for (int i = 1; i <= n; i++){
        cin >> weight[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> value[i];
    }

    for (int i = 1; i <= n; i++){
        int w = weight[i];
        int v = value[i];
        for (int j = 0; j < w; j++){
            DP1[i][j] = DP1[i-1][j];
        }
        for (int j = w; j <= B; j++){
            DP1[i][j] = max(DP1[i-1][j-w] + v, DP1[i-1][j]);
        }
    }
    for (int i = n; i >= 1; i--){
        int w = weight[i];
        int v = value[i];
        for (int j = 0; j < w; j++){
            DP2[i][j] = DP2[i+1][j];
        }
        for (int j = w; j <= B; j++){
            DP2[i][j] = max(DP2[i+1][j-w] + v, DP2[i+1][j]);
        }
    }

    for (int i = 1; i <= n; i++){
        int result = 0;
        int w = weight[i];
        for (int j = 0; j <= B+w; j++){
            if (j >= w and j <= B){
                result = max(result, DP1[i-1][j] + DP2[i+1][j-w]);
            }
            else if (j <= B){
                result = max(result, DP1[i-1][j]);
            }
            else if (j >= w){
                result = max(result, DP2[i+1][j-w]);
            }
        }
        cout << result << ' ';
    }
    return 0;
}
