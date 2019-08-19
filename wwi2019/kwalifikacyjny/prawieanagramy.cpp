#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    unordered_map<char, int> m1;
    cin >> s1 >> s2;
    if (s1.size() != s2.size()){
        cout << "NIE\n";
        return 0;
    }
    int err = 0;
    for (char c : s1){
        m1[c]++;
    }
    for (char c : s2){
        m1[c]--;
    }
    for (auto a : m1){
        //cout << a.second << '\n';
        err += abs(a.second);
    }
    if (err == 0){
        cout << "ANAGRAMY\n";
    }
    else if (err == 2){
        cout << "PRAWIE\n";
    }
    else {
        cout << "NIE\n";
    }
    return 0;
}