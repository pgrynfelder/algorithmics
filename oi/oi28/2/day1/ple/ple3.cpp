#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
constexpr long long oo = 5e14 + 7;

int n;
long long W[N];
long long res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    set<pair<long long, int>, greater<pair<long long, int>>> current;
    long long c = 0;
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
        current.emplace(W[i], i);
        c += W[i];
    }
    res[n] = c;
    for (int k = n - 1; k > 0; k--) {
        for (auto it = current.begin(); it != current.end(); it++) {
            c = res[k + 1] - it->first;
            int cnt = 0;
            bool valid = true;
            for (int i = 1; i <= n; i++) {
                if (W[i] <= c) {
                    if (i == it->second) {
                        valid = false;
                        break;
                    }
                    c -= W[i];
                    cnt++;
                }
            }

            if (cnt >= k and valid) {
                res[k] = res[k + 1] - it->first;
                current.erase(it);
                break;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        cout << res[k] << " ";
    }
    return 0;
}