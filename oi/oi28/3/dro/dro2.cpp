#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e4 + 7, S = 5e4 + 7, K = 107;
constexpr long long oo = 1e16;
long long x[S], y[S], res[K][N];
// map<int, pair<long long, int>> graph[N];  // source -> bus -> (x0, target)
// vector<int> graph[N];
vector<int> stops[S];
int n, m, s, k;
long long t_start;
map<int, long long> t0[N];  // vertex -> bus -> t0
map<int, long long> w[N];

// int buses_needed(){
//     vector<int> d(n+1, oo);
//     d[0] = 0;

// }

inline long long mod(long long a, long long b) {
    long long res = a % b;
    return res < 0 ? res + b : res;
}

// https://aleshkev.github.io/ACC/index.html#szybkie-io
typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
    o << "[";
    for (auto i = v.begin(); i != v.end(); ++i) {
        o << *i;
        if (i != prev(v.end())) o << ", ";
    }
    o << "]";
    return o;
}
template <typename T, typename U>
ostream &operator<<(ostream &o, const pair<T, U> &v) {
    o << "(" << v.first << ", " << v.second << ")";
    return o;
}

#ifdef UNITEST
#define g getchar
#define p putchar
#else
#define g getchar_unlocked
#define p putchar_unlocked
#endif
inline bool iswhite(char c) { return c == ' ' || c == '\n'; }

struct fast_io {
    char eat_blank() {
        char c = g();
        while (iswhite(c)) c = g();
        return c;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, fast_io>::type operator>>(T &x) {
        x = 0;
        for (char c = eat_blank(); !iswhite(c); c = g()) x = 10 * x + c - '0';
        return *this;
    }
    fast_io &operator>>(char *s) {
        for (char c = eat_blank(); !iswhite(c); c = g()) *(s++) = c;
        *s = '\0';
        return *this;
    }
    fast_io &operator>>(string &s) {
        s = "";
        for (char c = eat_blank(); !iswhite(c); c = g()) s.push_back(c);
        return *this;
    }

    fast_io &operator<<(char c) {
        p(c);
        return *this;
    }
    template <typename T>
    typename enable_if<is_integral<T>::value, fast_io>::type operator<<(T x) {
        if (x == 0)
            p('0');
        else {
            char d[20];
            int32_t i = 0;
            for (; x > 0; x /= 10) d[i++] = '0' + x % 10;
            for (--i; i >= 0; --i) p(d[i]);
        }
        return *this;
    }
    fast_io &operator<<(char *s) {
        while (*s) p(*(s++));
        return *this;
    }
    fast_io &operator<<(const string &s) {
        return operator<<((char *)s.c_str());
    }
} io;

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    io >> n >> m >> s >> k >> t_start;
    bool subtask_1 = k == n;
    bool subtask_4 = t_start == 0;
    bool subtask_3 = true;

    k++;  // k means used buses now

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        io >> a >> b >> c;
        w[a][b] = w[b][a] = c;
        // graph[a].emplace_back(b);
        // graph[b].emplace_back(a);
    }
    for (int i = 1; i <= s; i++) {
        int l;
        io >> l >> x[i] >> y[i];
        if (l != 2) subtask_3 = false;
        if (x[i] != 0 or y[i] != 1) subtask_4 = false;
        stops[i].resize(l);
        for (int &a : stops[i]) io >> a;
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

    if (subtask_3) {
        for (int i = 1; i <= k; i++) {
            res[i - 1][1] = min(res[i - 1][1], t_start);

            for (int bus = 1; bus <= s; bus++) {
                int a = stops[bus][0], b = stops[bus][1];
                long long t = res[i - 1][a];
                long long t00 = t0[a][bus];
                if (t <= t00) {
                    res[i][b] = min(res[i][b], t00 + w[a][b]);
                } else {
                    long long y0 = y[bus];
                    res[i][b] =
                        min(res[i][b], t + mod(t00 - t, y[bus]) + w[a][b]);
                }
                res[i][b] = min(res[i][b], res[i - 1][b]);
            }
        }
        if (res[k][n] == oo)
            io << "NIE\n";
        else
            io << res[k][n] << "\n";
    } else if (subtask_1 or true) {
        for (int i = 1; i <= k; i++) {
            res[i - 1][1] = min(res[i - 1][1], t_start);

            for (int bus = 1; bus <= s; bus++) {
                map<int, long long> currentres;
                for (auto it = ++stops[bus].begin(); it != stops[bus].end();
                     it++) {
                    int a = *prev(it), b = *it;
                    long long t = res[i - 1][a];
                    long long t00 = t0[a][bus];
                    long long y0 = y[bus];

                    if (currentres.find(a) == currentres.end()) {
                        currentres[a] = oo;
                    }

                    if (t <= t00) {
                        currentres[a] = min(currentres[a], t00);
                    } else {
                        currentres[a] =
                            min(currentres[a], t + mod(t00 - t, y0));
                    }

                    if (currentres.find(b) == currentres.end())
                        currentres[b] = oo;

                    currentres[b] = min(currentres[b], currentres[a] + w[a][b]);

                    res[i][b] = min(res[i][b], res[i - 1][b]);
                }
                for (auto [v, val] : currentres)
                    res[i][v] = min(res[i][v], val);
            }
        }

        if (res[k][n] == oo)
            io << "NIE\n";
        else
            io << res[k][n] << "\n";
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