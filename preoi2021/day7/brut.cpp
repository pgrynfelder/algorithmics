#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 7;
vector<int> t;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int m = 1; i - m + 1 >= 1 and i + m - 1 <= n; m++) {
            bool works = true;
            for (int j = 1; j <= m; j++) {
                works = works and t[i - m + j] >= j;
            }
            for (int j = 1; j <= m; j++) {
                works = works and t[i + m - j] >= j;
            }
            if (works)
                res = max(res, m);
        }
    }
    cout << res;

    return 0;
}
