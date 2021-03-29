/*
PREOI 2021 FINAL
ROZ
https://sio2.staszic.waw.pl/c/preoi-2021/p/roz/

Piotr Grynfelder
*/


#include <bits/stdc++.h>
using namespace std;

__uint128_t sqrt_bs(__uint128_t x) {
    __uint128_t l = 1, r = x + 1;
    while (l < r) {
        __uint128_t m = (l + r) / 2;
        if (m * m > x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--) {
        bool res = false;
        uint64_t c;
        uint64_t c64;
        cin >> c64;
        c = c64;
        if (c == 0){
            cout << "TAK\n";
            continue;
        }
        for (uint64_t x = 1; x * x * x <= c; x++) {
            if (c % x == 0) {
                uint64_t y = c / x;
                uint64_t a_plus_b = sqrt_bs((4 * y - x * x) / 3);
                uint64_t a = (a_plus_b - x) / 2;
                uint64_t b = (a_plus_b + x) / 2;
                uint64_t c2 = (b - a) * (a * a + a * b + b * b);

                if (c == c2) {
                    // cout << (uint64_t) b << " " << (uint64_t) a << "\n";
                    res = true;
                    break;
                }
            }
        }
        cout << (res ? "TAK" : "NIE") << "\n";
    }
}

/*

4
2
8
56
9

1
1000000000000000000

1
999999999999999999
*/