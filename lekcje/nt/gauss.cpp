#include<bits/stdc++.h>
#define zero(x) (abs(x) <= eps)
using namespace std;

constexpr long double eps = 1e-4;
constexpr int MAX_N = 1007, MAX_M = 1007;
int n, m;
vector<vector<long double>> es;
vector<long double> sol;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    es = vector<vector<long double>>(n+1, vector<long double>(m+2));
    sol = vector<long double>(m+1);
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
        for (int y = x+1; y <= n; y++){
            if (!zero(es[y][x])){
                for (int j = x+1; j <= m + 1; j++){
                    es[y][j] -= es[x][j] * es[y][x] / es[x][x];
                }
                es[y][x] -= es[x][x] * es[y][x] / es[x][x];
            }
        }
    }
    for (int x = n; x >= 1; x--){
        int i = 1;
        while (i <= m){
            if (!zero(es[x][i])){
                break;
            }
            i++;
        }
        // cout << i << "\n"; 
        if (i == m + 1 and !zero(es[x][i])){
            cout << "sprzeczny\n"; return 0;
        }
        else if (i == m + 1 and zero(es[x][i])){
            continue;
        }
        else {
            sol[i] = es[x][m+1] / es[x][i];
            for (int j = i + 1; j <= m; j++){
                sol[i] -= sol[j] * es[x][j] / es[x][i];
            }
        }
    }
    for (int i = 1; i <= m; i++){
        cout << fixed << setprecision(6) << sol[i] << "\n";
    }
    return 0;      
}
