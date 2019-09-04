#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

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
    for (int i = 0; i < n; i++){
        cin >> things[i].m;
    }
    for (int i = 0; i < n; i++){
        cin >> things[i].v;
        things[i].i = i;
    }

    vector<vector<ll>> t(n+1, vector<ll>(b+1, 0));
    for (auto &a : t){a[0] = 0;}
    for (int j = 1; j <= n; j++) {
        Thing &thing = things[j-1];
        for (int i = 0; i <= b; i++){
            t[j][i] = t[j-1][i];
            if (i >= thing.m){
                if (t[j-1][i-thing.m] + thing.v > t[j-1][i]){
                    t[j][i] = t[j-1][i-thing.m] + thing.v;
                }
            }
        }
    }

    cout << t[n][b] << '\n';
    
    stack<int> toprint;
    int i = b, j = n;
    while (j > 0 and i > 0){
        if (t[j][i] == t[j-1][i]){
            j--;
        }
        else {
            toprint.push(j);
            i -= things[j-1].m;
            j--;
        }
    }
    cout << toprint.size() << '\n';
    while(!toprint.empty()){
        cout << toprint.top() << ' '; toprint.pop();
    }
    cout << '\n';
    
    return 0;
}