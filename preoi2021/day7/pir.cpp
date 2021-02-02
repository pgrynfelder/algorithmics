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

    vector<int> left(n + 2), right(n + 2);
    // from left 1,2,3...m
    for (int i = 1; i <= n; i++) {
        left[i] = min(left[i - 1] + 1, t[i]);
    }
    // from right m...3,2,1
    for (int i = n; i >= 1; i--) {
        right[i] = min(right[i + 1] + 1, t[i]);
    }
    int best = 0;
    for (int i = 1; i <= n; i++) {
        // cout << left[i] << " : " << right[i] << "\n";
        best = max(best, min(left[i], right[i]));
    }

    cout << best;

    return 0;
}
