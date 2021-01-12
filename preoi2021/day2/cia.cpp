#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, a, b, cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> a >> b;

    ll lo = x, hi = x, loi = 0, hii = 0;
    for (int i = 1; i <= n; i++) {
        ll y;
        cin >> y;
        x += y;
        if (lo > x) {
            lo = x;
            loi = i;
        }
        if (hi < x) {
            hi = x;
            hii = i;
        }
        if (hi - lo > b - a) {
            if (hii > loi) {
                cout << "-1";
                return 0;
            } else {
                cnt++;
                lo = hi = x;
                loi = hii = i;
            }
        }
    }
    cout << cnt;

    return 0;
}