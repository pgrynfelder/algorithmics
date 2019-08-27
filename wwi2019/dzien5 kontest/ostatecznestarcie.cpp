#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> sorted;
vector<int> parent;
int n, s, last_working_k;

int solve(int k){
    vector<int> subtree(n+1);
    int result = 0;

    for (int v : sorted){
        subtree[v] = 1;
        for (int u : G[v]){
            if (u != parent[v]){
                subtree[v] += subtree[u];
            }
        }
        if (subtree[v] >= k){
            subtree[v] = 0;
            result++;
        }
    }
    if (result >= s){
        last_working_k = k;
        return true;
    }
    return false;
}

int dfs(int v){
    for (int u : G[v]){
        if (u != parent[v]){
            parent[u] = v;
            dfs(u);
        }
    }
    sorted.push_back(v);
}

int bs(int l, int r){
    while (l < r){
        int mid = (l+r)/2;
        if (!solve(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    G.resize(n+1);
    parent.resize(n+1);

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(1);

    bs(0,n+1);
    cout << last_working_k << '\n';

    return 0;

}   

/*

12 4
1 9
2 9
3 10
4 10
5 11
6 11
7 11
8 12
9 10
10 12
11 12

*/