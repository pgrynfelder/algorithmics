#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<int, int> tunnels[200000];
    int n, k, m;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        cin >> tunnels[i].first >> tunnels[i].second;
    }
    cout << tunnels;
}