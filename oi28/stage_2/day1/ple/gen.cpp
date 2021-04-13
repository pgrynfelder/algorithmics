#include <bits/stdc++.h>
using namespace std;
int random(int a, int b) { return rand() % (b - a + 1) + a; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i = 0;
    cin >> i;
    srand(i);
    int n = random(1, 100);
    cout << n << "\n";
    for (int j = 1; j <= n; j++) cout << random(1, 1000) << " ";

    return 0;
}