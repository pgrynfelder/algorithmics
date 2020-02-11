#include<bits/stdc++.h>
using namespace std;


vector<int> pref;
string s;
int n;
int i, L, R;

void print(){
    cout << s << "\n";
    for (int j = 0; j < n; j++){
        if (j == i) cout << "i";
        else cout << " ";
    }
    cout << "\n";
    for (int j = 0; j < n; j++){
        if (j == L) cout << "L";
        else cout << " ";
    }
    cout << "\n";
    for (int j = 0; j < n; j++){
        if (j == R) cout << "R";
        else cout << " ";
    }
    cout << "\n";
    for (int j = 0; j < n; j++){
        cout << pref[j];
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    // s = "#" + s;
    n = s.size();
    pref.resize(n);
    print();
    for (i = 1, L = 0, R = 0; i < n; i++){
        if (i < R){
            pref[i] = min(R-i, pref[i-L]);
        }
        while(i + pref[i] < n and s[pref[i]] == s[i + pref[i]]){
            pref[i]++;
        }
        if (i + pref[i] > R){
            L = i; 
            R = i + pref[i];
        }
        print();
    }
    for (int i = 0; i < n; i++){
        cout << pref[i];
    }
    return 0;
}