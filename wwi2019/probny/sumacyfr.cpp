#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    long long r = 0;
    for (char c : s){
        r += c - '0';
    }
    cout << r << '\n';
}