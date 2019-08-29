#include<bits/stdc++.h>
using namespace std;


constexpr int N = 1e6+7;
int PS[2*N];
string word;
string a, b;
int result[2*N];

void knp(){
    PS[0] = -1;
    PS[1] = 0;
    for (int i = 2; i < word.size(); i++){
        int candidate = PS[i-1];
        while (candidate >= 0 and word[candidate+1] != word[i]){
            candidate = PS[candidate];
        }
        PS[i] = candidate + 1;

        int backtracker = 0;
        if (i > b.size()+1) backtracker = PS[i];
        while (backtracker >= 0){
            result[backtracker+1]++;
            backtracker = PS[backtracker];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> b >> a;
    word = "$" + b + "#" + a + "&";
    
    knp();
    // for (int i = 0; i < a.size() + b.size() + 2; i++){
    //     cout << PS[i] << ' ';
    // }
    // cout << endl;
    
    for (int i = 2; i < b.size()+2; i++){
        cout << result[i] << ' ';
    }
    return 0;
}