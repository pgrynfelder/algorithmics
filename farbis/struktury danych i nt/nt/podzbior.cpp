// podzbior, subset, subset of given xor
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ull n, q;
    cin >> n >> q;
    
    set<ull, greater<ull>> xd;
    while (n--){
        ull a;
        cin >> a;
        for (ull b : xd){
            // cout << "y:" << y <<" ";
            a = min(a, a^b);
        }
        
        if (a != 0) xd.insert(a);   
    }
    while (q--){
        ull a;
        cin >> a;
        for (ull b : xd){
            a = min(a, a^b);
        }
        if (a == 0){
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
    return 0;      
}

/*

8 1
144
36
180
203
125
201
0
146
125


3 4
1 4 12
0
6
8
9
*/