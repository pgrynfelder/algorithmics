#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string word){
    uint32_t n = word.size();
    for (uint32_t i = 0; i < n; i++){
        if (toupper(word[i]) != toupper(word[n - i - 1])) return false;
    }
    return true;
}

uint32_t letters[100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n;

    cin >> n;
    for (uint32_t i = 0; i < n; i++){
        cin.ignore();
        string text;
        getline(cin, text);

        for (char c : text){
            letters[c-'a']++;
        }
    }
    for (uint32_t i = 0; i < 100; i++){
        if (letters[i] > 0){
            cout << char(i + 'a') << ' ' << letters[i] << "\n";
        }
    }

    return 0;
}