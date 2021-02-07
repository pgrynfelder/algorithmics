#include <bits/stdc++.h>
using namespace std;

constexpr int N = 307;
int n, m, q;
vector<vector<bool>> t;
pair<int, int> match[N][N], def = {-1, -1};
bool visited[N][N];
constexpr pair<int, int> neighbours[] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

bool augment(int i, int j) {
    visited[i][j] = true;
    for (auto neighbour : neighbours) {
        int i2 = i + neighbour.first, j2 = j + neighbour.second;
        if (t[i2][j2] and match[i2][j2] == def) {
            match[i2][j2] = {i, j};
            match[i][j] = {i2, j2};
            return true;
        }
    }
    for (auto neighbour : neighbours) {
        int i2 = i + neighbour.first, j2 = j + neighbour.second;
        auto [imatch, jmatch] = match[i2][j2];
        if (t[i2][j2] and !visited[imatch][jmatch] and
            augment(imatch, jmatch)) {
            match[i2][j2] = {i, j};
            match[i][j] = {i2, j2};
            return true;
        }
    }
    return false;
}
void matching() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) match[i][j] = def;

    while (true) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) visited[i][j] = false;
        bool any = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (t[i][j] and match[i][j] == def and augment(i, j))
                    any = true;
        if (not any) break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> m;
        t.assign(n + 2, vector<bool>(m + 2, false));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                t[i][j] = (c == '.');
            }
        }
        matching();
        bool piotr = false;
        for (int i = 1; i <= n and !piotr; i++)
            for (int j = 1; j <= m and !piotr; j++)
                if (t[i][j] and match[i][j] == def) {
                    cout << "Piotr\n";
                    piotr = true;
                }
        if (!piotr) cout << "Krzysztof\n";
    }

    return 0;
}