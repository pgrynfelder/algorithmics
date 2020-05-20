#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;

int n;
int t[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    long long lowest = 0, res = 0, current = 0;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        current = current + t[i];
        lowest = min(lowest, current);
        res = max(res, current - lowest);
    }
    cout << res;
    return 0;
}
