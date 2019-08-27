#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

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
    int n, k;
    cin >> n >> k;
 
    cin >> word;
    word = "#" + word;
    prefix_suffix();
    for (int i = 1; i <= n; i++){
        int T = i - ps[i];
        cout << (i/T >= k) ? 1 : 0;
    }    
    
    return 0;
}
