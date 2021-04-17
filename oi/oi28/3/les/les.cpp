#include <bits/stdc++.h>
using namespace std;

constexpr long long oo = 1e18 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long d;
    vector<long long> pre, cur;
    cin >> n >> d;
    for (int q = 1; q <= n; q++) {
        int s;
        cin >> s;
        swap(pre, cur);
        cur.resize(s);
        for (auto& a : cur) cin >> a;

        if (q > 1) {
            int A = pre.size(), B = cur.size();
            pre.resize(A + B - 2, oo);
            cur.resize(A + B - 2, oo);
            // sort(pre.begin(), pre.end()); // already sorted
            long long res = oo;
            do {
                long long temp = 0;
                for (int i = 0; i < A + B; i++) {
                    if (pre[i] == oo and cur[i] == oo) {
                        // pass
                    } else if (pre[i] == oo) {
                        temp += min(cur[i], d - cur[i]);
                    } else if (cur[i] == oo) {
                        temp += min(pre[i], d - pre[i]);
                    } else {
                        temp += abs(pre[i] - cur[i]);
                    }
                }
                res = min(res, temp);
            } while (next_permutation(pre.begin(), pre.end()));
            cout << res << "\n";
            cur.resize(B);
        }
    }

    return 0;
}

/*

4 10
2 4 7
3 3 6 8
1 5
2 4 5

*/