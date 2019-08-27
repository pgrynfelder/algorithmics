#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+7;
int KMP[N][3];
string word;
void kmp(){
    KMP[0][0] = -1; KMP[1][0] = 0;
    for (int i = 2; i < word.size(); i++){
        int candidate = KMP[i-1][0];
        while (candidate >= 0 and word[candidate+1] != word[i]){
            candidate = KMP[candidate][0];
        }
        KMP[i][0] = candidate + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    word = "$" + a + "#" + b; 

    return 0;
}
