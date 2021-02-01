#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
char s[2 * N];
int n, l = N, r = N - 1;
set<int> periods;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            r++;
            cin >> s[r];
            vector<int> todelete;
            for (int p : periods)
                if (r - p >= l and s[r - p] != s[r])
                    todelete.emplace_back(p);
            for (int p : todelete)
                periods.erase(p);
        } else {
            l--;
            cin >> s[l];
            vector<int> todelete;
            for (int p : periods)
                if (l + p <= r and s[l + p] != s[l])
                    todelete.emplace_back(p);
            for (int p : todelete)
                periods.erase(p);
        }
        periods.emplace(r - l + 1);
        cout << periods.size() << "\n";
        // for (auto p : periods){
        //     cout << p << " ";
        // }
        // cout << "\n";
    }

    return 0;
}

/*
5
1 a
2 b
1 b
1 a
2 a
*/