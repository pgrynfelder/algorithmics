#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e3 + 7;
int n, q;

bitset<N> t[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            int x;
            cin >> x;
            t[a][b] = x;
        }
        t[a][a] = 1;
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        vector<int> query(k);
        bitset<N> mask, curr;
        for (int &a : query) {
            cin >> a;
            mask[a] = 1;
        }
        curr = mask;
        for (int a : query) {
            curr &= t[a];
        }
        int res = curr._Find_first();
        while (res != N){
            if ((t[res] & mask).count() == 1){
                break;
            }
            res = curr._Find_next(res);
        }
        cout << (res == N ? -1 : res) << "\n";
    }

    return 0;
}   