#include <bits/stdc++.h>
using namespace std;

typedef int64_t int64;

constexpr int64 N = 1e5 + 7;
int64 n, X, z;
vector<pair<int64, int64>> holes;
vector<int64> ans;

void printans() {
    for (int64 i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> X >> z;
    ans.resize(n + 1);
    for (int64 y = 1; y <= n; y++) {
        int64 k;
        cin >> k;
        for (int64 j = 1; j <= k; j++) {
            int64 x;
            cin >> x;
            holes.emplace_back(x, y);
        }
    }
    sort(holes.begin(), holes.end(), [&](auto a, auto b) { return a > b; });
    for (auto [x, y] : holes) {
        if (y + 1 <= n) {
            ans[y + 1] = min(ans[y + 1], ans[y] + 1);
            ans[y] = min(ans[y] + 1, ans[y + 1]);
        } else {
            ans[y] = ans[y] + 1;
        }
    }
    for (int i = 1; i <= z; i++) {
        int y;
        cin >> y;
        cout << ans[y] << "\n";
    }
    return 0;
}

/*

3 9 3
1 6
2 3 8
2 5 7
3
2
1

*/