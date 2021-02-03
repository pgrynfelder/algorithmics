#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) { return rand() % (b - a + 1) + a; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int seed;
    cin >> seed;
    srand(seed);
    int n = 10, m = 1e6;

    cout << 1 << "\n";
    cout << n << " " << random(1, n / 2) << "\n";
    for (int i = 1; i <= n; i++) {
        cout << random(1, m) << " ";
    }

    return 0;
}