#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 1, K = 47;
bitset<N> T;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    T[0] = 1;
    for (int i = 1; i < K; i++) {
        T = T | (T << (i * i * i));
    }
    for (int i = a; i <= b; i++) {
        if (T[i])
            cout << i << " ";
    }
    return 0;
}