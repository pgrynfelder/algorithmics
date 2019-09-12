#include<bits/stdc++.h>
using namespace std;

int things[107][2];
long long DP[107][10007];
int added[107][10007];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, B;
    cin >> n >> B;
    for (int i = 0; i < n; i++){
        cin >> things[i][0];
    }
    for (int i = 0; i < n; i++){
        cin >> things[i][1];
    }
    
    fill(&(DP[0][1]), &(DP[0][B]), LONG_LONG_MIN);

    for (int i = 0; i < n; i++){
        int w = things[i][0];
        int v = things[i][1];
        for (int j = 0; j < w; j++){
            added[i+1][j] = added[i][j];
            DP[i+1][j] = DP[i][j];
        }
        for (int j = w; j <= B; j++){
            if (DP[i][j-w] + v > DP[i][j]){
                added[i+1][j] = i+1;
                DP[i+1][j] = DP[i][j-w] + v;
            } else {
                added[i+1][j] = added[i][j];
                DP[i+1][j] = DP[i][j];
            }
        }
    }
    cout << DP[n][B] << '\n';
    int j = B;
    int i = n;
    set<int> result;
    while (i > 0 and j > 0){
        if (added[i][j] == 0) break;
        result.insert(added[i][j]);
        j -= things[added[i][j]-1][0];
        i--;
    }
    cout << result.size() << '\n';
    for (int i : result){
        cout << i << ' ';
    }
    return 0;
}

