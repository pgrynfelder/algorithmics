#include <bits/stdc++.h>

#include "dlulib.h"
using namespace std;

vector<int> cache;
int check(int p) {
    if (cache[p] == -1) {
        cache[p] = sprawdz(p);
    }
    return cache[p];
}

int main() {
    int n = daj_n();
    cache.assign(n + 1, -1);
    int l = 1, r = n;
    while (l < r) {
        int m = l + r >> 1;
        if (m + 1 <= n and check(m) > check(m + 1)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int res = check(l);

    int hi = check(1);
    l = 1, r = n;
    while (l < r) {
        int m = l + r >> 1;
        if (check(m) > hi) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    res = max(res, check(l));

    hi = check(n);
    l = 1, r = n;
    while (l < r) {
        int m = l + r >> 1;
        if (check(m) <= hi) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    res = max(res, check(max(l - 1, 1)));
    odpowiedz(res);
    return 0;
}