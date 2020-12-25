#include<bits/stdc++.h>
using namespace std;

constexpr int M = 2e5 + 7, N = 2e5 + 7;
int n, m;
struct edge {
    int v = 0, i = 0;
    edge (int _v, int _i){
        v = _v; i = _i;
    }
};
stack<int> res;
vector<edge> G[N];
bool visitedE[N];
int last[N];
int degin[N];
int degout[N];

void euler(int v){
    for ( ; last[v] < G[v].size(); last[v]++ ){
        auto &e = G[v][last[v]];
        if (!visitedE[e.i]){
            // visitedV[e.v] = 1;
            visitedE[e.i] = 1;
            euler(e.v);
        }
    }
    // cout << v << " ";
    res.push(v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        degout[a]++; degin[b]++;
        G[a].emplace_back(b, i);
    }
    int morein = 0, moreout = 0, start = 0;;
    for (int i = 1; i <= n; i++){
        if (degout[i] == degin[i] + 1){
            start = i;
            moreout++;
        }
        else if (degin[i] == degout[i] + 1){
            morein++;
        }
        else if (degin[i] == degout[i]){
            if (degin[i] and !start){
                start = i;
            }
        }
        else {
            cout << "NIE\n"; return 0;
        }
    }

    // cout << "in, out " << morein << " " << moreout << "\n";
    if (!((moreout == 0 and morein == 0) or (moreout == 1 and morein == 1))){
        cout << "NIE\n";
        return 0;
    }
    euler(start);
    for (int i = 1; i <= m; i++){
        if (!visitedE[i]){
            cout << "NIE\n"; return 0;
        }
    }
    cout << "TAK\n";
    while (res.size()){
        cout << res.top() << " "; res.pop();
    }
}

/*
6 7 
1 2
1 4
2 3
3 1
4 1
4 6
5 4

*/