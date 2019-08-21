#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    while (q-->0){
        char c;
        cin >> c;
        if (c == 'W'){
            int lca, a, b;
            cin >> lca;
            a = b = lca;
        
            while (a < n){
                a = a * 2;
                b = b * 2 + 1;
            }
            cout <<  a-n+1 << ' ' << b-n+1 << '\n';
        }
        if (c == 'P'){
            int a, b;
            cin >> a >> b;
            a += n-1;
            b += n-1;
            while (a!=b){
                a/=2;
                b/=2;
            }
            cout << a << '\n';
            
        }
    }
    return 0;
}

/*
8 4
W 1
P 5 8
W 10
P 3 4
*/