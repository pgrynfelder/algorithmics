#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll M1 = 1e9 + 123, M2 = 1e9 + 2161;
constexpr uint P = 107;

string s;
uint pref[N];
uint p1[N] = {1};


uint h(int i, int j){
    int x = (pref[j] - pref[i-1] * p[j-i+1]) % M1;
    if (x < 0) x+= M1;
    return x;
}
    

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= s.size(); i++){
        p1[i] = p1[i-1] * P % M1;
        pref[i] = ((ll)pref[i-1] * p1[1] + s[i]) % M1;
        
    }
}
