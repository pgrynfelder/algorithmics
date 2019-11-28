// podzbior, subset, subset of given xor
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

constexpr int MAX_N = 1007, MAX_M = 1007;
ull n, mod;
vector<vector<ull>> es;
vector<ull> sol;

ull p(ull m, ull n, ull mod){ 
    ull res = 1;
    while (n > 0) {
        if(n & 1) {
            res = m * res % mod;
        }
        m = m * m % mod;
        n >>= 1;
    }
    return res;
}

ull inv(ull n, ull mod){
    return p(n, mod-2, mod);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> mod;
    n++;
    es = vector<vector<ull>>(n, vector<ull>(n+1));
    sol = vector<ull>(n);
    for (int i = 0; i < n; i++){
        ull x, y;
        cin >> x >> y;
        x %= mod; y %= mod;
        ull res = 1;
        for (int j = 0; j < n; j++){
            es[i][j] = res;
            res = res * x % mod;
        }
        es[i][n] = y;
    }
    
    for (int x = 0; x < n; x++){
        for (int i = x; i < n; i++){
            if (es[i][x] > es[x][x]){
                swap(es[i], es[x]);
            }
        }
        for (int y = x+1; y < n; y++){
            if (es[y][x] != 0){
                ull k = es[y][x] * inv(es[x][x], mod) % mod;
                for (int j = x+1; j < n + 1; j++){
                    es[y][j] = (mod + es[y][j] - es[x][j] * k % mod) % mod;
                }
                es[y][x] = 0;
            }
        }
    }
    for (int x = n-1; x >= 0; x--){
        int i = 0;
        while (i < n){
            if (es[x][i] != 0){
                break;
            }
            i++;
        }
        // cout << i << "\n"; 
        if (i == n and es[x][i] != 0){
            cout << "sprzeczny\n"; return 0;
        }
        else if (i == n and es[x][i] == 0){
            continue;
        }
        else {
            sol[i] = es[x][n];
            for (int j = i + 1; j < n; j++){
                sol[i] = (mod + sol[i] - sol[j] * es[x][j] % mod) % mod;
            }
            sol[i] = sol[i] * inv(es[x][i], mod) % mod;
        }
    }
    for (int i = 0; i < n; i++){
        cout << sol[i] << "\n";
    }
    return 0;      
}
