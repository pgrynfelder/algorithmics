#include <bits/stdc++.h>
using namespace std;
constexpr int N = 25e4 + 7, K = 13, P = (1 << 13);
int n, k;
int cnt[P];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int p = 1 << k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < k; j++) {
            mask += (s[j] - '0') << (k - j - 1);
        }
        cnt[mask]++;
    }
    long long res = 0;
    for (int i = 1; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            res += (i & j) ? (long long)cnt[i] * cnt[j] : 0;
        }
        res += (long long)cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << res;
    return 0;
}

/*

8 4
1100
0011
1001
0110
0101
1010
0000
1111

*/