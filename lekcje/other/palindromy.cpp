#include<bits/stdc++.h>

using namespace std;

bool is_palindrome(string w){
    uint32_t n = w.size();
    if (n % 2 == 1){
        return false;
    }
    for (uint32_t i = 0; i < n; i++){
        if (w[i] != w[n-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string w = "", palindrome = "", current = "", resulta = "", resultb = "";
    uint32_t i = 0, j = 0;
    cin >> w;
    for (i = 0; i < w.size(); i++) {
        current += w[i];
        if (is_palindrome(current)){
            j = i;
            resultb += current + " ";
            current = "";
        }
    }
    // cout << i << " " << j << "\n";
    if ( i - 1 != j){
        cout << "NIE\n";
        return 0;
    }

    resulta = "";
    j = 0;
    // nie wiem jak maksymalne palindromy halp
    cout << resulta << "\n";
    cout << resultb << '\n';
	return 0;
}