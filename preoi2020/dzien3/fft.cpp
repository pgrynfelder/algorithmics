// treningi greedy zachłan
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7, M = 5e5 + 7;

struct span {
    int l = 0, r = 0, c = 0;
};

int n, m;

vector<span> timeline;
vector<int> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        timeline.push_back({l, r, c});
    }
    sort(timeline.begin(), timeline.end(),
         [](const auto &a, const auto &b) { return a.r < b.r; });
    for (span &s : timeline) {
        s.c -= upper_bound(res.begin(), res.end(), s.r) -
               lower_bound(res.begin(), res.end(), s.l);
               
        while (s.c > 0) {
            res.push_back(s.r);
            s.c--;
        }
    }
    cout << res.size() << "\n";
    for (int &t : res){
        cout << t << " ";
    }
    return 0;
}

/*
10 6
2 6 4
1 4 2
5 8 1
1 10 7
1 1 1
6 7 2

*/