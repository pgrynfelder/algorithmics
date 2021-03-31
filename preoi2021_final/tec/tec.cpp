/*
PREOI 2021 FINAL
TEC

O(n log n)
100

Piotr Grynfelder
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7, W = N, H = N;
int n, m, k;

vector<pair<int, int>> L[W], R[W];       // {h, color}
map<int, int> color = {{0, 0}, {N, N}};  // color[h]
int invalid = 0;

int colors[N], various = 0;
void add(int c){
    if (colors[c] == 0) various++;
    colors[c]++;
}
void remove(int c){
    colors[c]--;
    if (colors[c] == 0) various--;
}

int res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int h = 1; h <= m; h++) {
        int l, r, c;
        cin >> l >> r >> c;
        L[l].emplace_back(h, c);
        R[r].emplace_back(h, c);
    }

    for (int w = 1; w <= n; w++) {
        for (auto [h, c] : L[w]) {
            auto nxt = color.lower_bound(h), prv = prev(nxt);
            if (prv->second >= nxt->second) invalid--;
            if (c <= prv->second) invalid++; 
            if (c >= nxt->second) invalid++;

            color[h] = c;
            add(c);
        }

        if (invalid == 0 and various == k){
            res++;
            // cout << w << " valid!\n";
        }

        for (auto [h, c] : R[w]) {
            auto cur = color.find(h), prv = prev(cur), nxt = next(cur);
            if (c <= prv->second) invalid--;
            if (c >= nxt->second) invalid--;
            if (prv->second >= nxt->second) invalid++;

            color.erase(h);
            remove(c);

        
        }
    }

    cout << res;

    return 0;
}