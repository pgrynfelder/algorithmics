#include<bits/stdc++.h>
using namespace std;

const int N = 16e6+7;

string word; // $word in order to index from 1
int ps[N]; // prefix_suffix array

void prefix_suffix(){
    int n = word.size();
    ps[1] = 0; ps[0] = -1;
    for (int i = 2; i < n; i++){
        int candidate = ps[i-1];
        while (candidate >= 0 and word[i] != word[candidate+1]){
            candidate = ps[candidate];
        }
        ps[i] = candidate + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    string word1, word2;
    cin >> word1 >> word2;
    word = "#" + word1 + "$" + word2;
    prefix_suffix();
    for (int i = 1; i <= n+m+1; i++) if (ps[i] == n)cout << i - 2*n << '\n'; 
    return 0;
}