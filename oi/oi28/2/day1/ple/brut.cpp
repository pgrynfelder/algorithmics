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
    long long sumw = 0;
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
        sumw += W[i];
        res[i] = oo;
    }
    for (long long c = 1; c <= sumw; c++) {
        long long current = c;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (W[i] <= current) {
                current -= W[i];
                cnt++;
            }
        }
        res[cnt] = min(res[cnt], c);
    }
    for (int i = n - 1; i >= 1; i--) {
        res[i] = min(res[i + 1], res[i]);
    }
    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}