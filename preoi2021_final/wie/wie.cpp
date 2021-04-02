/*
PREOI 2021 FINAL
WIE
25/100

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, M = 1e5 + 7;
int l[N], r[N], x[M], k[M];
bool used[N];
vector<int> odwiert[M], g[N];
int n, m;

struct action {
    int id, pos, typ;
    action(int _id = 0, int _pos = 0, int _typ = 0) {
        id = _id, pos = _pos, typ = _typ;
    }
    bool operator<(action &other) {
        return make_pair(pos, typ) < make_pair(other.pos, other.typ);
    }
};

bool visited[N];
vector<int> postorder;
void dfs(int a) {
    for (int b : g[a]) {
        if (!visited[b]) {
            visited[b] = 1;
            dfs(b);
        }
    }
    postorder.emplace_back(a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int a = 1; a <= n; a++) cin >> l[a] >> r[a];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int a;
            cin >> a;
            odwiert[i].emplace_back(a);
            used[a] = true;
        }
    }

    // vector<int> untouched;
    // for (int a = 1; a <= n; a++)
    //     if (!used[a]) untouched.emplace_back(a);
    // for (int i = 1; i < untouched.size(); i++)
    //     g[untouched[i - 1]].emplace_back(untouched[i]);
    // int highest_untouched = (untouched.empty() ? 0 : untouched[0]);

    vector<action> actions;
    for (int a = 1; a <= n; a++) {
        actions.emplace_back(a, l[a], 0);
        actions.emplace_back(a, r[a], 2);
    }
    for (int i = 1; i <= m; i++) actions.emplace_back(i, x[i], 1);
    sort(actions.begin(), actions.end());

    set<int> current;
    for (auto [id, pos, typ] : actions) {
        if (typ == 0) {
            current.emplace(id);
        } else if (typ == 2) {
            current.erase(id);
        } else if (k[id]) {
            current.erase(odwiert[id][0]);
            for (int i = 1; i < k[id]; i++) {
                current.erase(odwiert[id][i]);
                g[odwiert[id][i - 1]].emplace_back(odwiert[id][i]);
            }

            for (int b : current) g[odwiert[id].back()].emplace_back(b);

            for (int i = 0; i < k[id]; i++) {
                current.emplace(odwiert[id][i]);
            }
        }
    }

    for (int a = 1; a <= n; a++) {
        if (!visited[a]) {
            visited[a] = 1;
            dfs(a);
        }
    }
    reverse(postorder.begin(), postorder.end());
    for (int a : postorder) {
        cout << a << " ";
    }
    return 0;
}

/*
4
1 5
2 7
7 10
1 11
3
1 1 1
4 1 2
7 2 2 3
*/