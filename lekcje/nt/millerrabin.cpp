#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

constexpr int K = 36, L = 2, R = 37;

ull trailing_zeros(ull x){
    ull count = 0;
    while ((x & 1) == 0){
        x >>= 1;
        count++;
    }
    return count;
}

ull p(ull m, ull n, ull mod){ 
    ull res = 1;
    while (n > 0) {
        if(n & 1) {
            res = res * m % mod;
        }
        m = m * m % mod;
        n >>= 1;
    }
    return res;
}
// jeden rabin powie tak a drugi powie nie 
bool rabin(ull n){
    if (n==1) return false;
    else if (n==2) return true;
    else if (n==3) return true;
    ull s = trailing_zeros(n);
    ull d = n / (1 << s);
    cout << s << " " << d << "\n";
    for (int a = L; a <= R; a++){
        ull x = p(a, d, n);
        bool composite = true;
        if (x % n != 1){
            composite = false;
        }
        for (int i = 0; i < s; i++){
            if (x % n != n-1){
                composite = false;
            }
            x = x * x % n; 
        }
        if (composite) return false;
    }
    return true;
}

    
    
int main(){
    ull n;
    cin >> n;
    cout << rabin(n);   
    return 0;
}
