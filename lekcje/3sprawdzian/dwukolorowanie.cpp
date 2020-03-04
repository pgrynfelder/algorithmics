#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;

int n, m;
vector<int> G[N];
int color[N];

bool dfs(int v){
    bool works = true;
    for (int u : G[v]){
        if (color[u] == 0){
            color[u] = (color[v] & 1) + 1;
            works &= dfs(u);
        }
        else if (color[u] == color[v]){
            return false;
        }
    }
    return works;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    color[1] = 1;
    if (dfs(1)){
        cout << "TAK\n";
        for (int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
    }
    else {
        cout << "NIE\n";
    }
    return 0;
}
/* 
4 4
1 2
2 3
3 4
4 1
*/