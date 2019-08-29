#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+7;
int KMP[N][3];
int I[N][3];
string word;
int n, m;
void kmp(){
    KMP[0][0] = -1; KMP[1][0] = 0;
    for (int i = 2; i < word.size(); i++){
        // KMP proper
        int candidate = KMP[i-1][0];
        while (candidate >= 0 and word[candidate+1] != word[i]){
            candidate = KMP[candidate][0];
        }
        KMP[i][0] = candidate + 1;
        I[i][0] = i - KMP[i][0] + 1;
        
        // rewriting to [1]
        if (word[i] == word[i-1]){
            if (KMP[i-1][0] >= KMP[i-1][1]){
                KMP[i][1] = KMP[i-1][0];
                I[i][1] = I[i-1][0];
            }
            else {
                KMP[i][1] = KMP[i-1][1];
                I[i][1] = I[i-1][1];
            }
        }

        // generating [2]
        int candidate1 = KMP[i-1][1];
        while (candidate1 >= 0 and word[candidate1+1] != word[i]){
            candidate1 = KMP[candidate1][0];
        }
        candidate1++;

        int candidate2 = KMP[i-1][2];
        while (candidate2 >= 0 and word[candidate2+1] != word[i]){
            candidate2 = KMP[candidate2][0];
        }
        candidate2++;

        if (candidate1 >= candidate2){
            KMP[i][2] = candidate1;
            I[i][2] = I[i-1][1];
        }
        else {
            KMP[i][2] = candidate2;
            I[i][2] = I[i-1][2];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    word = "$" + a + "#" + b; 
    kmp();
    // for (int j = 0; j < 3; j++){
    //     for (int i = 1; i < n + m + 2; i++){
    //         if (KMP[i][j] / 10 < 1) cout << ' ';
    //         cout << KMP[i][j] << ' ';
    //     }
    //     cout << '\n';
    //     for (int i = 1; i < n + m + 2; i++){
    //         if (I[i][j] / 10 < 1) cout << ' ';
    //         cout << I[i][j] << ' ';
    //     }
    //     cout << "\n\n";
    // }
    set<int> result = {0};

    for (int i = n+1; i < n + m + 2; i++){
        for (int j = 0; j < 3; j++){
            if (KMP[i][j] == n){
                result.insert(I[i][j]);
            }
        }
    }
    result.erase(0);
    cout << result.size() << '\n';
    for (int c : result){
        cout << c - n - 1 << ' ';
    }
    cout << '\n';
    return 0;
}
