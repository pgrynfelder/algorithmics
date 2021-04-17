#include <bits/stdc++.h>
using namespace std;

int random(int a, int b) { return rand() % (b - a + 1) + a; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i;
    cin >> i;
    srand(i);
    // cout << random(0, 10);
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<long long> dist(0, 1e18);
    cout << dist(gen);
    return 0;
}