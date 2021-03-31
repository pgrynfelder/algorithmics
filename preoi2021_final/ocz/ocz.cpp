#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int m = s2.size();
        s1 = "#" + s1;
        s2 = "*" + s2;
        int q;
        cin >> q;

        if (q == 1) {
            int l, r;
            cin >> l >> r;
            int n = r - l + 1;
            vector<vector<int>> t(n + 2, vector<int>(m + 2));
            for (int y = 1; y <= m; y++) {
                for (int x = 1; x <= n; x++) {
                    if (s2[y] == s1[x + l - 1])
                        t[x][y] = t[x - 1][y - 1] + 1;
                    else
                        t[x][y] = max(t[x - 1][y], t[x][y - 1]);
                }
            }
            int lcs = t[n][m];
            // cout << lcs << " lcs\n";
            cout << m + n - 2 * lcs << "\n";
        } else {
            int n = s1.size() - 1;
            vector<vector<vector<int>>> lcs(n + 1);
            for (int l = 1; l <= n; l++) {
                lcs[l] = vector(n - l + 2, vector<int>(m + 2));
                for (int y = 1; y <= m; y++) {
                    for (int x = 1; x <= n - l + 1; x++) {
                        if (s2[y] == s1[x + l - 1])
                            lcs[l][x][y] = lcs[l][x - 1][y - 1] + 1;
                        else
                            lcs[l][x][y] =
                                max(lcs[l][x - 1][y], lcs[l][x][y - 1]);
                    }
                }
            }
            while (q--) {
                int l, r;
                cin >> l >> r;
                int lcss = lcs[l][r - l + 1][m];
                cout << r - l + 1 + m - 2 * lcss << "\n";
            }
        }
    }

    return 0;
}