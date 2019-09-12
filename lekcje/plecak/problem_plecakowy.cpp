#include<bits/stdc++.h>
using namespace std;

int things[107][2];
long long DP[107][10007];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, B;
    cin >> n >> B;
    for (int i = 1; i <= n; i++){
        cin >> things[i][0];
    }
    for (int i = 1; i <= n; i++){
        cin >> things[i][1];
    }

    for (int i = 1; i <= n; i++){
        int w = things[i][0];
        int v = things[i][1];
        for (int j = 0; j < w; j++){
            DP[i][j] = DP[i-1][j];
        }
        for (int j = w; j <= B; j++){
            DP[i][j] = max(DP[i-1][j-w] + v, DP[i-1][j]);
        }
    }
    cout << DP[n][B] << '\n';
    
    vector<int> result;
    int j = B;
    for (int i = n; i > 0; i--){
        if (DP[i][j] != DP[i-1][j]){
            result.push_back(i);
            j -= things[i][0];
        }
    }
    cout << result.size() << '\n';
    for (int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << ' ';
    }
    //cout << endl;

    return 0;
}

