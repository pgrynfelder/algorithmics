#include<bits/stdc++.h>
using namespace std;
/*
    Smuteczek mocno bo ten solv to kwadrat :( 
*/
const int N = 2e6+7;
int KMP[N];
int KMP2[N];
string word;
string word2;
int n, m;

int last_same_letter[N];

void kmp(){
    KMP[0] = -1; KMP[1] = 0;
    for (int i = 2; i < word.size(); i++){
        int candidate = KMP[i-1];
        while (candidate >= 0 and word[candidate+1] != word[i]){
            candidate = KMP[candidate];
        }
        KMP[i] = candidate + 1;
    }
}

void kmp2(){
    KMP2[0] = -1; KMP2[1] = 0;
    for (int i = 2; i < word2.size(); i++){
        int candidate = KMP2[i-1];
        while (candidate >= 0 and word2[candidate+1] != word2[i]){
            candidate = KMP2[candidate];
        }
        KMP2[i] = candidate + 1;
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
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    word2 = "$" + a + "#" + b;
    kmp2();
    int last_i = word.size()-1;
    for (int i = word.size()-1; i >= a.size()+2; i--){
        if (word[i] != word[last_i]){
            last_i = i;
        }
        last_same_letter[i - a.size() - 2] = last_i - a.size() - 2;
    }
    // for (int i = 0; i < word.size() - a.size() - 2; i++){
    //     cout << last_same_letter[i] << ' ';
    // }
    // cout << '\n';
    reverse(KMP2, KMP2+word2.size());
    // for (int i = a.size()+2; i < word.size(); i++){
    //     cout << KMP[i] << ' ';
    // }
    // cout << '\n';
    vector<vector<int>> matches(a.size()+1);
    for (int i = 0; i < b.size(); i++){
        // cout << KMP2[i] << ' ';
        matches[KMP2[i]].push_back(i);
    }

    // cout << '\n' << endl;
    set<int> XD;
    //vector<int> XD;
    for (int i = a.size()+2; i < word.size(); i++){
        int current_match = KMP[i];
        int current_i = i - a.size() - 2;
        if (current_match == a.size()){
            XD.insert(current_i - current_match + 2);
            //XD.push_back(current_i - current_match + 2);
            current_match = KMP[current_match];
        }
        while (current_match != 0){
        //if (current_match == 0) continue;

        if (!matches[a.size() - current_match].empty()){
            auto back_it = 
            lower_bound(matches[a.size()-current_match].begin(), 
            matches[a.size()-current_match].end(), 
            current_i+2);
            if (back_it != matches[a.size()-current_match].end()){
                int back_i = *back_it;
                if (current_i + 2 <= back_i){
                    if (last_same_letter[current_i+1] >= back_i or last_same_letter[current_i] >= back_i - 1 ){
                    //if (last_same_letter[current_i] >= back_i - 1 ){    
                        XD.insert(current_i - current_match + 2);
                        //XD.push_back(current_i - current_match + 2);
                    }
                }
            }
        }
        current_match = KMP[current_match];
        }
    }
    cout << XD.size() << '\n';
    for (int c : XD){
        cout << c << ' ';
    }
    cout << "\n";
    return 0;
}
