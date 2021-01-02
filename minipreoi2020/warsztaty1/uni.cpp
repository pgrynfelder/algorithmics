// gasienica bucket
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7, A = 1e6 + 7;
int n;

int cnt[A], repetitions = 0;
void add(int a) {
    if (cnt[a] == 1) {
        repetitions++;
    }
    cnt[a]++;
}
void remove(int a) {
    if (cnt[a] == 2) {
        repetitions--;
    }
    cnt[a]--;
}

int t[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int maxlen = 0;
    // [l, r)
    for (int l = 0, r = 0; r <= n; r++) {
        while (repetitions) {
            remove(t[l]);
            l++;
        }
        maxlen = max(maxlen, r - l);
        add(t[r]);
    }
    cout << maxlen;
    return 0;
}