/*
PREOI 2021 FINAL
KOL
https://sio2.staszic.waw.pl/c/preoi-2021/p/kol/

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e6 + 7, M = 1e6 + 7, LOGN = 23;
int n, m, d, id, a;
int tail[M], jptr[N][LOGN], val[N], s[M];

void push(int x, int k) {
    id++;
    val[id] = x;
    jptr[id][0] = tail[k];
    for (int i = 1; i < LOGN; i++) jptr[id][i] = jptr[jptr[id][i - 1]][i - 1];
    tail[k] = id;
    s[k]++;
}

int pop(int k) {
    int tojump = s[k] - 1;
    int v = tail[k];
    for (int i = LOGN - 1; i >= 0; i--) {
        if (tojump >= (1 << i)) {
            tojump -= (1 << i);
            v = jptr[v][i];
        }
    }
    s[k]--;
    a = val[v];
    return val[v];
}

// copies queue l to k
void copy(int k, int l) {
    tail[k] = tail[l];
    s[k] = s[l];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == 'U') {
            int x, k;
            cin >> x >> k;
            if (d)
                push(x ^ a, k ^ a);
            else
                push(x, k);

        } else if (c == 'Z') {
            int k;
            cin >> k;
            if (d)
                cout << pop(k ^ a) << "\n";
            else
                cout << pop(k) << "\n";

        } else if (c == 'I') {
            int k, l;
            cin >> k >> l;
            if (d)
                copy(k ^ a, l ^ a);
            else
                copy(k, l);
        }
    }

    return 0;
}