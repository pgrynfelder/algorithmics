#include<bits/stdc++.h>
#define zero(x) (abs(x) <= eps)
using namespace std;

constexpr double eps = 1e-5;
constexpr int MAX_N = 1007, MAX_M = 1007;
int n, m;
vector<vector<double>> es;
vector<double> solutions;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    es = vector<vector<double>>(n+1, vector<double>(m+2));
    solutions = vector<double>(m+1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m + 1; j++){
            cin >> es[i][j];
        }
    }
    
    for (int x = 1; x <= m; x++){
        for (int i = x; i <= n; i++){
            if (abs(es[i][x]) > abs(es[x][x])){
                swap(es[i], es[x]);
            }
        }
        for (int i = x+1; i <= n; i++){
            if (!zero(es[i][x])){
                double k = es[x][x] / es[i][x];
                for (int j = x; j <= m + 1; j++){
                    es[i][j] -= es[x][j] / k;
                }
            }
        }
    }
    for (int x = 1; x <= n; x++){
        for (int i = 1; i <= m+1; i++){
            cout << es[x][i] <<  " ";
        }
        cout << "\n";
    }
    for (int x = n; x >= 1; x--){
        int i;
        for (i = 1; i <= m+1; i++){
            if (i == m + 1){
                cout << "sprzeczny\n";
                return 0;
            }
            if (!zero(es[x][i])) break;
        }
        
    }
    return 0;      
}
