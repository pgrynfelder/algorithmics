/*
TAK
25 OI
https://szkopul.edu.pl/problemset/problem/pxbqUTPy3IuPDul9FdT2_Sth/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;
// constexpr int N = 10;
int n;
long long a[N], b[N];
int ranking[N];

struct Q {
    long long p, q;
    Q(long long _p, long long _q = 1) {
        // long long d = gcd(_p, _q);
        // p = _p / d, Q = _q / d;
        p = _p, q = _q;
        if (_q < 0) {
            p *= -1;
            q *= -1;
        }
    }
};
bool operator<(const Q &a, const Q &b) { return a.p * b.q < b.p * a.q; }
ostream &operator<<(ostream &os, const Q &a) {
    long long d = gcd(a.p, a.q);
    return os << a.p / d << "/" << a.q / d;
}

/*
i <= j

a_i x + b_i <= a_j x + b_j
(a_i - a_j) x <= b_j - b_i

case I: a_i == a_j -> 0 <= b_j - b_i -> add to cnt if not satisfied
case II: a_i > a_j -> x <= (b_j - b_i) / (a_i - a_j) -> add to upper bound
case III: a_i < a_j -> x >= (b_j - b_i) / (a_i - a_j)  -> add to lower bound

*/

int invalid = 0;
multiset<Q> lb = {Q(1, 1e9)}, ub = {Q(1e9)};

void add_constraints(int i, int j) {
    if (i == 0 or j == 0) return;
    if (a[i] == a[j]) {
        if (b[i] > b[j]) invalid++;
    } else if (a[i] > a[j]) {
        ub.emplace(b[j] - b[i], a[i] - a[j]);
    } else {
        lb.emplace(b[j] - b[i], a[i] - a[j]);
    }
}
void remove_constraints(int i, int j) {
    if (i == 0 or j == 0) return;
    if (a[i] == a[j]) {
        if (b[i] > b[j]) invalid--;
    } else if (a[i] > a[j]) {
        ub.erase(ub.find(Q(b[j] - b[i], a[i] - a[j])));
    } else {
        lb.erase(lb.find(Q(b[j] - b[i], a[i] - a[j])));
    }
}
void check() {
    if (invalid > 0 or *ub.begin() < *lb.rbegin())
        cout << "NIE\n";
    else
        cout << *lb.rbegin() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> b[i] >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> ranking[i];
    }
    for (int i = 1; i <= n; i++) {
        add_constraints(ranking[i], ranking[i + 1]);
    }
    check();
    int z;
    cin >> z;
    while (z--) {
        int i, j;
        cin >> i >> j;

        for (int x : set<int>{i - 1, i, j - 1, j})
            remove_constraints(ranking[x], ranking[x + 1]);

        swap(ranking[i], ranking[j]);

        for (int x : set<int>{i - 1, i, j - 1, j})
            add_constraints(ranking[x], ranking[x + 1]);

        check();
    }

    return 0;
}

/*

3
8 3
12 2
9 4
2 1 3
3
1 3
1 2
2 3

4/1
NIE
1/1
2/1


*/