#include<bits/stdc++.h>
using namespace std;

struct T {
    int n = 1;
    vector<int> t;
    T (int _n){
        while (n < _n) n <<= 1;
        t.resize(n << 1);
    }
    int lca(int a, int b){
        while (a != b){
            a >>= 1; b >>= 1;
        }
        return a;
    }
    void finance(int i, int x){
        i += n;
        t[i] += x;
        while(i > 1){
            i >>= 1;
            mod[i] = max(mod[i << 1], mod[(i << 1) + 1]);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    return 0;
}
