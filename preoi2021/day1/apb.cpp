#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7, M = 1e9 + 7;
int n, m;

vector<int> in, out, ins, outs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    in.resize(n + 1);
    out.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> in[i] >> out[i];
        ins.push_back(in[i]);
        outs.push_back(out[i]);
    }

    sort(ins.begin(), ins.end());
    sort(outs.begin(), outs.end());

    for (int i = 1; i <= n; i++) {
        cout << (outs.end() - lower_bound(outs.begin(), outs.end(), in[i])) -
                    (ins.end() -
                     lower_bound(ins.begin(), ins.end(), out[i] + 1)) -
                    1
             << "\n";
    }

    return 0;
}