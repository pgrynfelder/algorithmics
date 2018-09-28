#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string word){
    uint32_t n = word.size();
    for (uint32_t i = 0; i < n; i++){
        if (toupper(word[i]) != toupper(word[n - i - 1])) return false;
    }
    return true;
}

uint32_t upper[100];
uint32_t lower[100];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n;

    cin >> n;
    cin.ignore();
    for (uint32_t i = 0; i < n; i++){
        string text;
        getline(cin, text);

        for (char c : text){
            if (c >= 'a' and c <= 'z'){
                lower[c-'a']++;
            }
            else if (c >= 'A' and c <= 'Z'){
                upper[c-'A']++;
            }
        }
    }
    for (uint32_t i = 0; i < 100; i++){
        if (lower[i] > 0){
            cout << char(i + 'a') << ' ' << lower[i] << "\n";
        }
    }
    for (uint32_t i = 0; i < 100; i++){
        if (upper[i] > 0){
            cout << char(i + 'A') << ' ' << upper[i] << "\n";
        }
    }

    return 0;
}