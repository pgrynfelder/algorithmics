#include<bits/stdc++.h>
using namespace std;
int n, a;
const int N = 507;
const int M = 2*N*N;
// const int M = 20;
const int C = M/2 - 2;

int numbers[N];
bool DP[N][M];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a;
    for (int i = 1; i <= n; i++){
        cin >> numbers[i];
        numbers[i] -= a;
    }
    
    queue<int> result;
    DP[1][C + numbers[1]] = true;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < M; j++){
            DP[i][j] = DP[i-1][j];
            if (j-numbers[i] < M and j - numbers[i] >= 0)
                DP[i][j] = DP[i][j] or DP[i-1][j-numbers[i]];
        }
        if (DP[i][C]){
            cout << "TAK\n";
            int j = C;
            while (i > 0){
                if (DP[i-1][j] != true) {
                    j -= numbers[i];
                    result.push(numbers[i]);
                }
                i--;
            }
            cout << result.size() << '\n';
            while (!result.empty()){
                cout << result.front() + a << ' ';
                result.pop();
            }
            return 0;
        }
    }

    cout << "NIE\n";
    return 0;
}
