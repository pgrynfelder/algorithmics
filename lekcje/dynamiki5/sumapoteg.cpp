#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, K = 107;
int bc[K][K]; /// i choose j (binomial coefficent)
unsigned long long n;
int k;
int inv[K];
int previous[K];
int current[K];

int power(int m, unsigned long long n){
    int res = 1;
    while (n > 0) {
        if(n & 1) {
            res = (unsigned long long)res * m % mod;
        }
        m = (unsigned long long)m * m % mod;
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
    for (int i = 0; i <= k; i++){
        bc[i][0] = 1;
    }
    for (int j = 1; j <= k; j++){
        bc[j][j] = 1;
        for (int i = j + 1; i <= k; i++){
            bc[i][j] = (((unsigned long long)bc[i-1][j] * i) % mod * inv[i - j]) % mod;
        }
    }
}

/*
f(2n, k) = f(n, k) + sum(i = 0, i <= k, (k over i) * n^(k-i) * f(n, i))
f(n+1, k) = f(n, k) + (n+1)^k
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    calculate_inv();
    calculate_bc();
    
    stack<int> q;
    while (n > 0){
        q.push(n);
        if (n & 1){
            n = n ^ 1;
        }
        else {
            n = n >> 1;
        }
    }
    while (!q.empty()){
        n = q.top(); q.pop();
        if (n & 1){
            int multiplier = n % mod;
            int pown = 1;
            for (int i = 0; i <= k; i++){
                current[i] = ((unsigned long long)previous[i] + pown) % mod;
                pown = (unsigned long long)pown * multiplier % mod; 
            } 
        }
        else {
            int multiplier = (n/2) % mod;
            for (int i = 0; i <= k; i++){
                current[i] = previous[i];
                int pown = 1;
                for (int j = 0; j <= i; j++){
                    current[i] = (current[i] + (unsigned long long)bc[i][j] * pown % mod * previous[i-j]) % mod;
                    pown = (unsigned long long)pown * multiplier % mod;
                }
            }
        }
        for (int i = 0; i <= k; i++){
            previous[i] = current[i];
        }
    }

    cout << current[k] << "\n";
    
    
    return 0;
}

