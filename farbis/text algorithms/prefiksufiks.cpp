#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

constexpr ull k = 31, M = 2147483647;
constexpr int N = 1e6 + 7;
ull p[N] = {1, 107};
ull t[N];
bool ps[N];
int xd[N];
int n;
string s;

ull mod(ull x){
	x = (x >> k) + (x & M);
	x = (x >> k) + (x & M);
	return x == M ? 0 : x;
}

ull gethash(int i, int j){
    return mod(M + t[j] - mod(p[j - i + 1] * t[i-1]));
}

bool eq(int i1, int j1, int i2, int j2){
    return gethash(i1, j1) == gethash(i2, j2);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 2; i <= n; i++){
        p[i] = mod(p[i-1] * p[1]);
    }
    for (int i = 0; i < n; i++){
        t[i+1] = mod(t[i] * p[1] + s[i]);
    }
    ps[0] = true;
    for (int i = 1; i <= n/2; i++){
        ps[i] = eq(1,i, n-i+1, n);
    }

    int j = n/2 - 2;
    for (int i = n/2; i >= 1; i--){ // t_i -> first: i, last: n+1-i
        j = min(j+2, (n-2*(i-1))/2);
        while (j > 0 and not eq(i, i+j-1, n+1-i-(j-1), n+1-i)){
            j--;
        }
        xd[i] = j;
    }
    // for (int i = 1; i <= n/2; i++) cout << xd[i] << ' ';
    int res = 0;
    for (int i = 1; i <= n/2; i++){
        if (ps[i-1]) res = max(res, i-1 + xd[i]);
    }
    cout << res;
    return 0;
}
