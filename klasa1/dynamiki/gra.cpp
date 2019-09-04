#include<bits/stdc++.h>

using namespace std;
typedef unsigned uint;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    uint n;
    cin >> n;
    vector<vector<uint>> A(n);
    vector<uint> S(n+1);
    auto s = [&](uint a, uint b){return S[b+1]-S[a]; };
    for (int i = 0; i < n; i++){
        uint a;
        cin >> a;
        A[0].push_back(a);
        S[i+1] = S[i] + a;
    }
    
    for (int j = 1; j < n; j++){
        for (int i = 0; i + j < n; i++){
            A[j].push_back(s(i, i+j) - min(A[j-1][i], A[j-1][i+1]));
        }
    }
    cout << A[n-1][0] << ' ' << S[n] - A[n-1][0] << '\n';

}