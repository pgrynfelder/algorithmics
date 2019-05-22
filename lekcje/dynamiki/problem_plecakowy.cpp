#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
//const ll inf = 1e6+7;
const int inf = 1e9+7;

struct Thing {
    int m, v, i;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b;
    cin >> n >> b;
    vector<Thing> things(n);
    for (ll i = 0; i < n; i++){
        cin >> things[i].m;
    }
    for (ll i = 0; i < n; i++){
        cin >> things[i].v;
        things[i].i = i;
    }

    vector<vector<int>> t(n+1, vector<int>(b+1, 0));
    for (auto &a : t){a[0] = 0;}
    for (int j = 1; j <= n; j++) {
        Thing &thing = things[j-1];
        for (int i = b; i >= thing.m; i--){
            if (t[j-1][i-thing.m] + thing.v > t[j-1][i]){
                t[j][i] = t[j-1][i-thing.m] + thing.v;
            }
            else {
                t[j][i] = t[j-1][i];
            }
        }
    }

    cout << t[n][b] << '\n';
    
    vector<int> toprint;
    int i = b, j = n;
    while (j > 0 and i > 0){
        if (t[j][i] == t[j-1][i]){
            j--;
        }
        else {
            toprint.push_back(j);
            i -= things[j-1].m;
            j--;
        }
    }
    cout << toprint.size() << '\n';
    reverse(toprint.begin(), toprint.end());
    for (auto &number : toprint){
        cout << number << ' ';
    }
    cout << '\n';
    
    return 0;
}