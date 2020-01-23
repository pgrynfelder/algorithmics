#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr ull M = 1e9+7, N = 3e5+7;
ull DP[2][N];
ull P[N] = {1};


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

ull product(ull i, ull j){
    return (ull)P[j] * inv(P[i-1]) % M;
}

ull n, k;
struct xd {
    ull mod = 0;
    queue<pair<ull,ull>> q;
    void add(ull x, ull i){
        mod += x;
        q.emplace(x - mod, i);
    }
    pair<ull, ull> top(){
        return {q.front().first + mod, q.front().second};
    }
    void pop(){
        q.pop();
    }
    bool empty(){
        return q.empty();
    }
};

xd Q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (ull i = 1; i <= n; i++){
        ull a;
        cin >> a;
        P[i] = (ull)P[i-1] * a % M;
        Q.add(a, i);
        DP[0][i] = (ull)DP[0][i-1] + DP[1][i-1] % M;
        DP[1][i] = (ull)DP[1][i-1]*a % M;
        while (!Q.empty() and Q.top().first > k){
            DP[1][i] = ((ull)DP[1][i] + product(Q.top().second, i)) % M; 
            Q.pop();
        }

    }
    ull res = ((ull)DP[0][n] + DP[1][n]) % M;
    cout << res << "\n";
    return 0;
}
