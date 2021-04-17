/*
    Piotr Grynfelder
    pitek1
    Zadanie PRO
    28 OI
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 107;

bool t[N][N];
vector<int> horizontal, vertical;
bool pre;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long k;
    cin >> k;
    if (k == 0) {
        cout << "1\n#";
        return 0;
    }
    int a = 1, b = 1;
    while (k > 1) {
        t[a][b] = t[a][b + 1] = t[a + 1][b] = true;
        if (k & 1) {
            t[a + 1][b + 1] = true;
            if (pre) {
                horizontal.emplace_back(a);
                a++;
            } else {
                vertical.emplace_back(b);
                b++;
            }
            pre = !pre;
        }
        k /= 2;
        a++;
        b++;
    }
    t[a][b] = true;
    if (pre) {
        horizontal.emplace_back(a);
    } else {
        vertical.emplace_back(b);
    }

    int n = max(a, b) + 2;
    for (int i = 1; i <= n; i++) {
        t[i][n] = t[n][i] = true;
    }
    for (int b : vertical) {
        for (int a = n - 1; t[a][b] != true; a--) {
            t[a][b] = true;
        }
    }
    for (int a : horizontal) {
        for (int b = n - 1; t[a][b] != true; b--) {
            t[a][b] = true;
        }
    }
    cout << n << '\n';

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            cout << (t[n - a + 1][n - b + 1] ? '.' : '#');
        }
        cout << '\n';
    }
    return 0;
}