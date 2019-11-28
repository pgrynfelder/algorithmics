// miller rabin prime
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

constexpr int K = 36, L = 2, R = 37;
ull primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ull trailing_zeros(ull x){
    ull count = 0;
    while ((x & 1) == 0){
        x >>= 1;
        count++;
    }
    return count;
}

ull mul(ull m, ull n, ull mod){ 
    ull res = 0;
    while (n > 0) {
        if(n & 1) {
            res = (res + m) % mod;
        }
        m = (m + m) % mod;
        n >>= 1;
    }
    return res;
}

ull p(ull m, ull n, ull mod){ 
    ull res = 1;
    while (n > 0) {
        if(n & 1) {
            res = mul(m, res, mod);
        }
        m = mul(m, m, mod);
        n >>= 1;
    }
    return res;
}


// jeden rabin powie tak a drugi powie nie 
bool rabin(ull n){
    if (n==1) return false;
    else if (n==2) return true;
    else if (n==3) return true;
    ull s = trailing_zeros(n-1);
    ull d = (n-1) / (1 << s);
    // cout << "n = 2^" << s << " * " << d << " + 1\n";
    // cout << s << " " << d << "\n";
    for (ull a : primes){
        if (a > n-2) break;
        ull x = p(a, d, n);
        
        bool composite = true;
        if (x == 1){
            // cout << x << "\n";
            continue;
        }
        for (ull i = 0; i < s; i++){
            // cout << x << "\n";
            if (x == n-1){
                composite = false;
            }
            x = mul(x, x, n); 
        }
        
        if (composite){
            // cout << "wypitol for x=" << x << "\n";
            return false;
        }
    }
    return true;
}

    
    
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ull n;
    cin >> n;
    while (n--){
        ull x;
        cin >> x;
        cout << (rabin(x) ? "TAK" : "NIE") << "\n";   
    }
    return 0;
}
