#include <bits/stdc++.h>
using namespace std;

constexpr int N = 507;
int n, m, t;
bitset<N * N> T;
bitset<N * N> mask;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    int row = m + 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            mask[i * row + j] = (s[j] == '.') ? 1 : 0;
        }
        mask[i * row + m] = 0;
    }
    T = mask;
    string s;
    cin >> s;
    for (int i = 0; i < t; i++) {
        char c = s[i];
        if (c == 'N') {
            T = (T >> row) & mask;
        } else if (c == 'S') {
            T = (T << row) & mask;
        } else if (c == 'E') {
            T = (T << 1) & mask;
        } else if (c == 'W') {
            T = (T >> 1) & mask;
        } else if (c == '?') {
            T = ((T << 1) | (T >> 1) | (T << row) | (T >> row)) & mask;
        }
    }
    cout << T.count();
    return 0;
}