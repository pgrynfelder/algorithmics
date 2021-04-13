/*
    Piotr Grynfelder
    PLA
*/

#include <bits/stdc++.h>
using namespace std;

constexpr long long K = 1e9 + 7;
constexpr int Z = 1e5 + 7;

int n, z;
long long X;
struct seg {
    long long a, b;
    int e;
    seg(long long _a, long long _b, int _e) {
        a = _a;
        b = _b;
        e = _e;
    }
    bool operator<(const seg &other) const {
        if (((b - a) << other.e) < ((other.b - other.a) << e)) {
            return true;
        } else if (((b - a) << other.e) == ((other.b - other.a) << e)) {
            return a > other.a;
        }
        return false;
    }
};

long long query[Z], ans1[Z], ans2[Z];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> X >> z;

    priority_queue<seg> Q;
    long long pre;
    cin >> pre;
    for (int i = 2; i <= n; i++) {
        long long cur;
        cin >> cur;
        Q.emplace(pre, cur, 0);
        pre = cur;
    }
    vector<int> queries;
    for (int i = 1; i <= z; i++) {
        cin >> query[i];
        queries.emplace_back(i);
    }
    sort(queries.begin(), queries.end(),
         [&](const int a, const int b) { return query[a] < query[b]; });

    auto it = queries.begin();
    long long k = 0;
    while (k < K and it != queries.end()) {
        auto s = Q.top();
        Q.pop();
        while (it != queries.end() and k < query[*it] and
               query[*it] <= k + (1 << s.e)) {
            long long d = query[*it] - k;
            ans1[*it] = s.a * (1 << (s.e + 1)) + (2 * d - 1) * (s.b - s.a);
            ans2[*it] = 1 << (s.e + 1);
            while ((ans1[*it] & 1) == 0 and (ans2[*it] & 1) == 0) {
                ans1[*it] /= 2;
                ans2[*it] /= 2;
            }
            it++;
        }

        k += (1 << s.e);
        s.e++;
        // cout << s.a << ", " << s.b << ", " << s.e << ", " << k << "\n";
        Q.push(s);
    }
    for (int i = 1; i <= z; i++) {
        cout << ans1[i] << '/' << ans2[i] << "\n";
    }
    return 0;
}

/*

5 10 5
0 2 3 7 10
1
2
5
6
8

*/