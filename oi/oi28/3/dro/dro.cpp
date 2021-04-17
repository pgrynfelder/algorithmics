#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e4 + 7, S = 5e4 + 7, K = 107;
constexpr long long oo = 1e16;

long long x[S], y[S], res[K][N];
vector<int> stops[S];
int n, m, s, k;
long long t_start;
map<int, long long> t0[N],  // vertex -> bus -> t0
    w[N];                   // vertex -> vertex -> weight

inline long long mod(long long a, long long b) {
    long long res = a % b;
    return res < 0 ? res + b : res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> k >> t_start;

    k++;  // k means used buses now

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
    }
    for (int i = 1; i <= s; i++) {
        int l;
        cin >> l >> x[i] >> y[i];
        stops[i].resize(l);
        for (int &a : stops[i]) cin >> a;
    }

    for (int i = 0; i <= k; i++)
        for (int j = 1; j <= n; j++) res[i][j] = oo;

    for (int i = 1; i <= s; i++) {
        t0[stops[i][0]][i] = x[i];
        for (auto it = ++stops[i].begin(); it != stops[i].end(); it++) {
            int pre = *prev(it), cur = *it;
            t0[cur][i] = t0[pre][i] + w[pre][cur];
        }
    }

    for (int i = 1; i <= k; i++) {
        res[i - 1][1] = min(res[i - 1][1], t_start);

        for (int bus = 1; bus <= s; bus++) {
            int ss = stops[bus].size();
            vector<long long> currentres(ss, oo);

            for (int j = 1; j < ss; j++) {
                int a = stops[bus][j - 1], b = stops[bus][j];
                long long t = res[i - 1][a], t00 = t0[a][bus], y0 = y[bus];

                if (t <= t00) {
                    currentres[j - 1] = min(currentres[j - 1], t00);
                } else {
                    currentres[j - 1] =
                        min(currentres[j - 1], t + mod(t00 - t, y0));
                }

                currentres[j] = min(currentres[j], currentres[j - 1] + w[a][b]);
            }
            for (int j = 0; j < ss; j++) {
                int a = stops[bus][j];
                res[i][a] = min(min(res[i][a], res[i - 1][a]), currentres[j]);
            }
        }

        if (res[k][n] == oo)
            cout << "NIE\n";
        else
            cout << res[k][n] << "\n";
    }

    return 0;
}

/*
4 4 2 1 1
1 2 2
2 3 4
1 3 3
4 3 2
4 0 10
1 2 3 4
3 2 7
1 3 2


3 0 2 1 5
2 3 8
1 2
2 4 3
2 3


10 9 9 10 123

1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
7 8 1
8 9 1
9 10 1

2 0 1
1 2
2 0 1
2 3
2 0 1
3 4
2 0 1
4 5
2 0 1
5 6
2 0 1
6 7
2 0 1
7 8
2 0 1
8 9
2 0 1
9 10

*/