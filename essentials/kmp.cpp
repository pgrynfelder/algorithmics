#include <bits/stdc++.h>

using namespace std;

// t - tekst
// w - wzorzec
// s= $w#t

int p[1000007];
string s;

void kmp(int n) { // n-długość sklejenia tekstu i wzorca
    int j = 0;
    p[0] = p[1] = 0;
    for (int i = 2; i <= n; i++) {
        while (j and s[i] != s[j + 1])
            j = p[j];
        if (s[i] == s[j + 1])
            j++;
        p[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;

    s = "$" + a + "#" + b;
    int n = size(s);
    kmp(n);
    for (int i = 0; i <= n; i++) {
        cout << p[i] << " ";
    }

    return 0;
}
