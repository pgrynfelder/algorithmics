#include<bits/stdc++.h>
using namespace std;


constexpr long long M = 1e9+7;
unsigned long long B[1000007] = {1, 313};
unsigned long long H[1000007];


unsigned long long get_hash(int l, int r){
    return (M + H[r] - H[l-1]*B[r - l + 1] % M) % M; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < 1000007; i++){
        B[i] = B[i-1] * B[1] % M;
    }
    int n;
    cin >> n;
    string word;
    cin >> word;
    for (int i = 1; i <= n; i++){
        H[i] = (H[i-1]*B[1] % M + word[i-1])%M; 
    }
    int q;
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        if (get_hash(a, (a+b)/2) == get_hash((a+b)/2+1, b)){
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n";
        }
    }
    
    return 0;
}
