// zamiatanie offline
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, K = 1e9 + 7, Q = 1e5 + 7;
int n, k, q;

vector<pair<int, int>> timeline;  // {miejsce, +-wartość} (zamiatańsko)
vector<pair<int, int>> questions; // {x, i}
int ans[Q];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> q;

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        timeline.emplace_back(a, c);
        timeline.emplace_back(b + 1, -c);
    }
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        questions.emplace_back(x, i);
    }
    sort(timeline.begin(), timeline.end(),
         [](const auto &a, const auto &b) { return a.first < b.first; });
    sort(questions.begin(), questions.end(),
         [](const auto &a, const auto &b) { return a.first < b.first; });
    int current = 0;
    auto j = questions.begin();
    for (auto &e : timeline) {
        while (e.first > j->first) {
            ans[j->second] = current;
            j++;
            if (j == questions.end())
                break;
        }
        if (j == questions.end())
            break;
        current += e.second;
    }
    while (j != questions.end()){
        ans[j->second] = current;
        j++;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
    return 0;
}