/*
OI24
MID
https://szkopul.edu.pl/problemset/problem/wrTmzO9-dzEbLtsRUCdMV2_W/site/?key=statement

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30, LOGN = 21;

struct node {
    node *l = nullptr, *r = nullptr, *jptr[LOGN];
    int d = 0, i;
    node(int _i = 0) {
        for (int j = 0; j < LOGN; j++) jptr[j] = this;
        i = _i;
    }
};

int n, q;

node *nodes[N], *remapped[N];
int d[N], L[N], R[N];

void dfs(node *a) {
    for (node *b : {a->l, a->r}) {
        if (b != a and b != nullptr) {
            b->d = a->d + 1;
            b->jptr[0] = a;
            for (int i = 1; i < LOGN; i++)
                b->jptr[i] = b->jptr[i - 1]->jptr[i - 1];
            dfs(b);
        }
    }
}

// solve with money for a go to b (a >= b)
bool solve(node *a, node *b) {
    if (b->d > a->d) return false;  // b deeper than a -> no chance

    // lca
    for (int i = LOGN - 1; i >= 0; i--)
        if (a->jptr[i]->d >= b->d) a = a->jptr[i];
    for (int i = LOGN - 1; i >= 0; i--)
        if (b->jptr[i]->d >= a->d) b = b->jptr[i];

    if (a == b) return true;

    for (int i = LOGN - 1; i >= 0; i--)
        if (a->jptr[i] != b->jptr[i]) a = a->jptr[i], b = b->jptr[i];

    node *parent = a->jptr[0];
    if (a == parent->r) {
        assert(b == parent->l);
        return true;
    }
    assert(a == parent->l and b == parent->r);
    return false;
}

vector<int> postorder;
void toposort(node *a) {
    for (node *b : {a->l, a->r}) {
        if (b != nullptr) {
            toposort(b);
        }
    }
    postorder.push_back(a->i);
}

void remap() {
    remapped[1] = new node();
    remapped[1]->l = remapped[1];

    for (auto it = postorder.rbegin(); it != postorder.rend(); it++) {
        int i = *it;
        assert(remapped[i] != nullptr);

        int a = L[i];
        int b = R[i];

        if (a != 0) {
            if (remapped[i]->l == nullptr) remapped[i]->l = new node();
            remapped[a] = remapped[i]->l;
        }
        if (b != 0) {
            if (remapped[i]->r == nullptr) remapped[i]->r = new node();
            remapped[b] = remapped[i]->r;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) nodes[i] = new node(i);

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        L[i] = a;
        R[i] = b;

        if (a != 0) nodes[i]->l = nodes[a];
        if (b != 0) nodes[i]->r = nodes[b];
    }

    cin >> q;

    toposort(nodes[1]);

    remap();

    dfs(remapped[1]);

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (solve(remapped[a], remapped[b]) ? "TAK" : "NIE") << "\n";
    }

    return 0;
}

/*

12
3 9
0 4
2 5
0 0
6 0
7 8
0 0
0 0
10 12
11 0
0 0
0 0
6
11 8
8 6
11 7
1 2
4 10
3 3


*/