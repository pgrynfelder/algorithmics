#include<bits/stdc++.h>
using namespace std;

vector<int> degin;
vector<vector<int>> G;
vector<int> sorted;

class Compare {
    public:
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    degin.resize(n+1);
    while (m--){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        degin[b]++;
    }

    priority_queue<int, vector<int>, Compare> q;
    for (int i = 1; i <= n; i++){
        if (degin[i] == 0) q.push(i);
    } 
    while (!q.empty()){
        int v = q.top();
        q.pop();
        sorted.push_back(v);
        for (int u : G[v]){
            degin[u]--;
            if (degin[u] == 0){
                q.push(u);
            }
        }
    }
    if (sorted.size() == n){
        cout << "TAK\n";
        for (int v : sorted){
            cout << v << ' ';
        }
    }
    else {
        cout << "NIE\n";
    }
    return 0;
}
/*
5 4
2 4
2 1
1 4
4 3
*/