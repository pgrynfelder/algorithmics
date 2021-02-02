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
    int n = 100, m = 1e3;

    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << random(0, m) << " ";
    }

    return 0;
}