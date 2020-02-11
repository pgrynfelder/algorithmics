/* manacher, palindrome */
#include<bits/stdc++.h>
using namespace std;

string s;
int L, R, i, m;
vector<int> P;
void print(){
    for (char c : s){
        cout << c << " ";
    }
    cout << "\n";
    for (int j = 0; j < s.size(); j++){
        if (j == i) cout << "i";
        else cout << " ";
        cout << " ";
    }
    cout << "\n";
    // for (int j = 0; j < s.size(); j++){
    //     if (j == L) cout << "L";
    //     else cout << " ";
    //     cout << " ";
    // }
    // cout << "\n";
    for (int j = 0; j < s.size(); j++){
        if (j == R) cout << "R";
        else cout << " ";
        cout << " ";
    }
    cout << "\n";
    for (int j = 0; j < s.size(); j++){
        if (j == m) cout << "m";
        else cout << " ";
        cout << " ";    
    }
    cout << "\n";
    for (int j = 0; j < s.size(); j++){
        cout << P[j] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string word;    
    cin >> word;
    s = "#";
    for (char c : word){
        s = s + c + "#";
    }
    P.resize(s.size());
    print();


    for (i = 0; i < s.size(); i++){
        if (i < R){
            P[i] = min(P[m - (i - m)], R - i);
        }
        int j = P[i];
        while (j + i + 1 < s.size() and i - j - 1 >= 0 and s[i+j+1] == s[i-j-1]){
            j++;
        }
        P[i] = j;
        if (i+j > R){
            R = i+j;
            m = i; 
        }
        print();
    }
    return 0;
}