#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+7;

vector<vector<long long>> t;

int n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    t = vector<vector<long long>>(n+1, vector<long long>(m+1));
    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> t[i][j];
        }
        sort(t[i].begin(), t[i].end());
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            t[i][j] += 2*j - 1;
            q.push(t[i][j]);
//            cout << t[i][j] << " ";

        }
//        cout << " selecting " << q.top();
        res += q.top(); q.pop();
//        cout << "\n";

    }
    cout << res << "\n";
}
