#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr ull M = 1e9 + 7;
constexpr ull N = 3e5+7;

ull fastpow(ull a, ull p){
    if (p==0){
        return 1;
    }
    if (p & 1){
        return (ull)a * fastpow(a, p-1) % M;
    }
    else {
        ull res = fastpow(a, p/2);
        return (ull)res * res % M;
    }
}

ull inv(ull a){
    return fastpow(a, M-2);
}
ull S[N]; 
ull P[N] = {1};
ull n, k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (ull i = 1; i <= n; i++){
        ull a;
        cin >> a;
        S[i] = S[i-1] + a;
        P[i] = (ull)P[i-1] * a % M;
    }
    ull res = 0;
    for (ull i = 1; i <= n; i++){
        for (ull j = i; j <= n; j++){
            if (S[j] - S[i-1] > k) res = (res + (ull) P[j] * inv(P[i-1])) % M;
        }
    }
    cout << res << "\n";
    return 0;
}
