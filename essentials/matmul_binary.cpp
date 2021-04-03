/*
matmul
binary matrix multiplication
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3 + 7;

struct matrix {
    int w, h;
    bitset<N> t[N];  // t[j][i] == M_i,j
    matrix(int _w, int _h) { w = _w, h = _h; }
};
matrix operator*(const matrix &a, const matrix &b) {  // a * b
    assert(a.w == b.h);
    int h = a.h, w = b.w;
    matrix res(w, h);

    for (int i = 1; i <= h; i++) {
        bitset<N> cur = 0;
        for (int j = 1; j <= w; j++) {
            cur[j] = cur[j] | a.t[j][i];
        }
        for (int j = 1; j <= w; j++) {
            res.t[j][i] = (cur & b.t[j]).any();
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}