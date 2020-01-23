#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr int M = 1e9+7, N = 3e5+7;
int DP[2][N];
int P[N] = {1};


int fastpow(int a, int p){
    if (p==0){
        return 1;
    }
    if (p & 1){
        return (ull)a * fastpow(a, p-1) % M;
    }
    else {
        int res = fastpow(a, p/2);
        return (ull)res * res % M;
    }
}

int inv(int a){
    return fastpow(a, M-2);
}

int product(int i, int j){
    return (ull)P[j] * inv(P[i-1]) % M;
}

int n, k;
struct xd {
    ull mod = 0;
    queue<pair<ull,int>> q;
    void add(ull x, int i){
        mod += x;
        q.emplace(x - mod, i);
    }
    pair<ull, int> top(){
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
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        P[i] = (ull)P[i-1] * a % M;
        Q.add(a, i);
        DP[0][i] = ((ull)DP[0][i-1] + DP[1][i-1]) % M;
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
