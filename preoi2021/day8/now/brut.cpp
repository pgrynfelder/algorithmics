
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<ll> d, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        cin >> n >> k;
        d.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        ll res = 1e15 + 7;
        for (ll mask = 0; mask < (1 << (n - 1)); mask++) {
            ll cnt = 0, cur = 0;
            bool valid = true;
            for (ll xd = mask, i = 1; xd > 0; xd >>= 1, i++) {
                if ((xd & 3) == 3) {
                    valid = false;
                    break;
                }
                if (xd & 1) {
                    cnt++;
                    cur += d[i] - d[i - 1];
                }
            }
            if (cnt == k and valid) res = min(res, cur);
        }

        cout << res << "\n";
    }
    return 0;
}