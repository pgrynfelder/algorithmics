#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, K = 107;
int bc[K][K]; /// i choose j (binomial coefficent)
long long n;
int k;
int inv[K];
int pown[K];

int power(int m, long long n){
    int res = 1;
    while (n > 0) {
        if(n & 1) {
            res = (long long)res * m % mod;
        }
        m = (long long)m * m % mod;
        n >>= 1;
    }
    return res;
}

void calculate_inv(){
    for (int i = 1; i <= k; i++){
        inv[i] = power(i, mod-2);
    }
}

void calculate_bc(){
    for (int j = 1; j <= k; j++){
        bc[j][j] = 1;
        for (int i = j + 1; i <= k; i++){
            bc[i][j] = (((long long)bc[i-1][j] * i) % mod * inv[i - j]) % mod;
        }
    }
}

/*
f(2n, k) = f(n, k) + sum(i = 0, i <= k, (k over i) * n^(k-i) * f(n, i))
f(n+1, k) = f(n, k) + (n+1)^k
*/
unordered_map<long long, int> F[K];

int f(int k, long long n){
    //cout << "calculating for k=" << k << " n=" << n << "\n";
    if (F[k].count(n)) return F[k][n];
    if (n == 1) return 1;
    if (n <= 0) return 0;
    if (k == 0) return n % mod;
    if (k == 1){
        F[k][n] = (((n % mod) * ((n + 1) % mod)) % mod) / 2 % mod;
        return F[k][n];
    }
    if (n & 1 == 0){
        int res = f(k, n/2);
        for (int i = 0; i <= k; i++){
            res = (res + (((long long)bc[k][i] * power(n/2 % mod, k-i)) % mod * f(i, n/2))) % mod;
        }
        F[k][n] = res;
        return res;
    }
    else {
        F[k][n] = (((long long)f(k, n-1) + power(n % mod, k))) % mod;
        return F[k][n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    calculate_inv();
    calculate_bc();
    int result = f(k, n);
    // if (result == 12) cout << n << k;
    // else 
    cout << result << "\n";
    return 0;
}

