#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+7;
int n, m;
string s;
bool t[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> s;
    int result = 1;
    int i = 0;
    for (char c : s){
        t[i] = c - '0';
        i++;
    }
    for (int i = 1; i < n; i++){
        if (t[i-1] != t[i]){
            result++;
        }
    }
    cout << result << " ";
    while (m--){
        int j;
        cin >> j;
        j--;
        
        if (j > 0 and t[j] != t[j-1]) result--;
        if (j < n - 1 and t[j] != t[j+1]) result--;
        t[j] ^= 1;
        if (j > 0 and t[j] != t[j-1]) result++;
        if (j < n - 1 and t[j] != t[j+1]) result++;
        cout << result << " ";
    }
    return 0;
}
