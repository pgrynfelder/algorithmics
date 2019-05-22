#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string word){
    uint32_t n = word.size();
    for (uint32_t i = 0; i < n; i++){
        if (toupper(word[i]) != toupper(word[n - i - 1])) return false;
    }
    return true;
}

vector<uint32_t> order;
uint32_t result[7];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t spaces = 0;
    uint32_t numbers = 0;
    uint32_t words = 0;
    uint32_t sentences = 0;
    uint32_t palindromes = 0;

    bool isSentence = false;
    bool isWord = false;
    bool isNumber = false;
    string word = "";

    string text;

    uint32_t a, n;
    cin >> n;
    for (uint32_t i = 0; i < n; i++){
        cin >> a;
        order.push_back(a);
    }
    cin.ignore();
    getline(cin, text);
    text += "*";
    //cout << text << "\n";

    for (char c : text){
        if (c == ' '){
            spaces++;
        }

        if ( (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') ){
            if (isWord){
                word += c;
            }
            else {
                word = "";
                word += c;
                isWord = true;
                isSentence = true;
                words++;
            }
        }
        else {
            if (isWord and isPalindrome(word) ) {
                palindromes++;
            }
            isWord = false;
        }
        
        if (c >= '0' and c <= '9' ){
            if (isNumber){
            }
            else {
                isNumber = true;
                numbers++;
            }
        }
        else {
            isNumber = false;
        }

        if (c == '.'){
            if (isSentence){
                isSentence = false;
                sentences++;
            }
        }
    }
    result[1] = spaces; result[2] = numbers; result[3] = words; result[4] = sentences; result[5] = palindromes;
    for (uint32_t i : order){
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}
