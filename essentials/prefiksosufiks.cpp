#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;
string s;
int prefsuf[N];

void prefix_suffix() {
    for (int i = 1; i < s.size() - 1; i++) {
        int candidate = prefsuf[i];
        while (s[candidate + 1] != s[i + 1] and candidate != 0) {
            candidate = prefsuf[candidate];
        }
        if (s[candidate + 1] == s[i + 1])
            prefsuf[i + 1] = candidate + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    s = "#" + s + "$";

    prefix_suffix();
    for (int i = 1; i < s.size(); i++)
        cout << prefsuf[i] << " ";
    return 0;
}
