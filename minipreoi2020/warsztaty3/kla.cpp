// spójne find union fu rozpójnianie reverse czas odwrotnie od tyłu time parallel binsearch
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int n, m, q;

// scaling t
vector<long long> T;

// edges
struct edge {
    int a = 0, b = 0;
    long long t = 0;
};
vector<edge> E;

// find union
int fu[N];
int fusize[N];

int f(int a) {
    if (fu[a] != a)
        fu[a] = f(fu[a]);
    return fu[a];
}
void u(int a, int b) {
    a = f(a);
    b = f(b);
    if (fusize[b] > fusize[a])
        swap(a, b);
    fu[b] = a;
    fusize[a] += fusize[b];
}

// queries
// vector<int> Q;
int L[N], R[N], A[N], B[N];
int mid(int i) { return L[i] + (R[i] - L[i]) / 2; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    E.resize(m);
    for (edge &e : E) {
        cin >> e.a >> e.b >> e.t;
        e.t = -e.t;
        T.emplace_back(e.t);
    }
    sort(T.begin(), T.end());
    for (edge &e : E) {
        e.t = lower_bound(T.begin(), T.end(), e.t) - T.begin();
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> A[i] >> B[i];
        // Q.emplace_back(i);
        R[i] = m + 1;
        L[i] = 0;
    }
    sort(E.begin(), E.end(),
         [](const edge &a, const edge &b) { return a.t < b.t; });

    bool run = true;
    while (run) {
        run = false;
        for (int a = 1; a <= n; a++) {
            fu[a] = a;
            fusize[a] = 1;
        }

        // sort(Q.begin(), Q.end(),
        //      [](const int &a, const int &b) { return mid(a) < mid(b); });
        //
        // bucket sort
        vector<int> Q;
        vector<vector<int>> bucket(m + 2);
        for (int i = 1; i <= q; i++) {
            bucket[mid(i)].emplace_back(i);
        }
        for (auto &val : bucket) {
            for (int i : val) {
                Q.emplace_back(i);
            }
        }

        // proper binsearch
        auto it = E.begin();
        for (int i : Q) {
            if (L[i] < R[i]) {
                run = true;
                while (it != E.end() and it->t < mid(i)) {
                    u(it->a, it->b);
                    it++;
                }
                if (f(A[i]) != f(B[i])) {
                    L[i] = mid(i) + 1;
                } else {
                    R[i] = mid(i);
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        // cout << L[i] << ": ";
        if (L[i] >= m + 1) {
            cout << "nigdy.\n";
        } else {
            cout << -T[L[i] - 1] << "\n";
        }
    }

    return 0;
}

/*

6 5
1 2 6
1 3 5
3 4 2
4 2 1
4 5 7
6
1 2
2 5
3 2
4 5
1 5
5 6

*/