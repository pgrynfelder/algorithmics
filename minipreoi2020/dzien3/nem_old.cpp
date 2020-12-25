#include <bits/stdc++.h>
using namespace std;
constexpr int N = 507;
int n, m, t;
vector<vector<bool>> T[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    T[0].resize(m, vector<bool>(n));
    T[1].resize(m, vector<bool>(n));
    T[2].resize(m, vector<bool>(n));
    for (int y = n - 1; y >= 0; y--) {
        string s;
        cin >> s;
        for (int x = 0; x < m; x++) {
            T[2][x][y] = T[0][x][y] = s[x] - '#';
        }
    }
    string s;
    cin >> s;
    for (int i = 1; i <= t; i++) {
        char c = s[i - 1];
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                T[i & 1][x][y] = false;
            }
        }
        if (c == 'N' or c == '?') {
            for (int x = 0; x < m; x++) {
                for (int y = 1; y < n; y++) {
                    T[i & 1][x][y] = T[i & 1][x][y] or
                                     (T[(i - 1) & 1][x][y - 1] and T[2][x][y]);
                }
            }
        }
        if (c == 'S' or c == '?') {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n - 1; y++) {
                    T[i & 1][x][y] = T[i & 1][x][y] or
                                     (T[(i - 1) & 1][x][y + 1] and T[2][x][y]);
                }
            }
        }
        if (c == 'W' or c == '?') {
            for (int x = 0; x < m - 1; x++) {
                for (int y = 0; y < n; y++) {
                    T[i & 1][x][y] = T[i & 1][x][y] or
                                     (T[(i - 1) & 1][x + 1][y] and T[2][x][y]);
                }
            }
        }
        if (c == 'E' or c == '?') {
            for (int x = 1; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    T[i & 1][x][y] = T[i & 1][x][y] or
                                     (T[(i - 1) & 1][x - 1][y] and T[2][x][y]);
                }
            }
        }
    }
    int res = 0;
    for (int y = n - 1; y >= 0; y--) {
        for (int x = 0; x < m; x++) {
            if (T[t & 1][x][y])
                res++;
        }
    }
    cout << res << "\n";
    return 0;
}
/*
5 9 7
...##....
..#.##..#
..#....##
.##...#..
....#....
WS?EE??
*/