// graph gen graph generator tree generator

#include <bits/stdc++.h>
using namespace std;

template <class c>
struct rge {
    c b, e;
};
template <class c>
rge<c> range(c i, c j) {
    return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);

struct debug {
    ~debug() { cerr << endl; }

    template <class c>
    typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return *this;
    }

    template <class c>
    typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return *this << range(begin(i), end(i));
    }

    template <class c, class b>
    debug& operator<<(pair<b, c> d) {
        return *this << "(" << d.first << ", " << d.second << ")";
    }

    template <class c>
    debug& operator<<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it) {
            *this << ", " + 2 * (it == d.b) << *it;
        }
        return *this << "]";
    }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int rand_int(int l, int r) { return l + rand() % (r + 1 - l); }

vector<pair<int, int>> generate_tree(int n) {
    vector<pair<int, int>> edges(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        edges[i] = make_pair(i + 2, rand_int(1, i + 1));
        if (rand_int(0, 1) == 0) {
            swap(edges[i].first, edges[i].second);
        }
    }
    random_shuffle(edges.begin(), edges.end());

    vector<int> p(n);
    for (int i = 1; i <= n; ++i) {
        p[i - 1] = i;
    }
    random_shuffle(p.begin(), p.end());
    for (int i = 0; i < n - 1; ++i) {
        edges[i].first = p[edges[i].first - 1];
        edges[i].second = p[edges[i].second - 1];
    }

    return edges;
}

vector<pair<int, int>> generate_connected_graph(int n, int m) {
    m = max(m, n - 1);
    m = min({(long long)m, (long long)2e5, (long long)n * (n - 1) / 2});

    vector<pair<int, int>> edges = generate_tree(n);

    map<pair<int, int>, bool> used;
    for (int i = 0; i < (int)edges.size(); ++i) {
        used[make_pair(edges[i].first, edges[i].second)] =
            used[make_pair(edges[i].second, edges[i].first)] = true;
    }

    edges.resize(m);
    for (int i = n - 1; i < m; ++i) {
        int u = rand_int(1, n), v = rand_int(1, n);
        while (u == v || used[make_pair(u, v)]) {
            u = rand_int(1, n), v = rand_int(1, n);
        }
        used[make_pair(u, v)] = used[make_pair(v, u)] = true;
        edges[i] = make_pair(u, v);
    }

    random_shuffle(edges.begin(), edges.end());
    vector<int> p(n);
    for (int i = 1; i <= n; ++i) {
        p[i - 1] = i;
    }
    random_shuffle(p.begin(), p.end());
    for (int i = 0; i < m; ++i) {
        edges[i].first = p[edges[i].first - 1];
        edges[i].second = p[edges[i].second - 1];
        if (rand_int(0, 1) == 0) {
            swap(edges[i].first, edges[i].second);
        }
    }

    return edges;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int seed;
    cin >> seed;
    srand(seed);

    int n = rand_int(1, 10);
    cout << n << "\n";

    auto edges = generate_tree(n);
    for (auto e : edges) {
        cout << e.first << ' ' << e.second << '\n';
    }
    int q = n * n;
    cout << q << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << " " << j << "\n";
        }
    }

    return 0;
}