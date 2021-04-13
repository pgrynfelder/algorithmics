#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1007;
int n, m, q;

int tab[N][N];
int cnt = 0;

void update(int i1, int j1, int i2, int j2) {
    pair<int, int> to_consider[] = {
        {i1 - 1, j1 - 1}, {i1 - 1, j2}, {i2, j1 - 1}, {i2, j2}};
    for (auto p : to_consider) {
        if (p.first >= 1 and p.second >= 1) {
            cnt -= tab[p.first][p.second];
            tab[p.first][p.second] ^= 1;
            cnt += tab[p.first][p.second];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        update(i1, j1, i2, j2);
        cout << cnt << "\n";
    }

    return 0;
}

/*

2 3 3
1 2 2 2
1 1 2 1
1 2 1 3

*/