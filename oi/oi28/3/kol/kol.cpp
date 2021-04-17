#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;
long long a[N], b[N];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long max_a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[N+1] >> b[N+1];
        max_a = max(max_a, a[i]);
    }

    long long res_b = b[1];

    for (int i = 2; i <= n; i++) {
        res_b = gcd(res_b, b[i]);
    }
    
    long long res = 0;
    for (long long k = max_a; k > 0; k--) {
        bool works = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] % k != 0 and b[i] % k != 0) {
                works = false;
                break;
            }
        }
        if (works) {
            cout << max(res_b, k);
            return 0;
        }
    }
    

    return 0;
}