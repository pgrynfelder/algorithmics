#include<bits/stdc++.h>
using namespace std;
struct edge {
    int w, d, t, o;
    edge (int _w, int _d, int _t, int _o){
        w = _w; d = _d; t = _t; o = _o;
    }
};
vector<vector<edge>> G;
vector<int> distances;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    G.resize(n+1);
    distances.resize(n+1);
    for (int i=1; i <= n; i++){
        int m;
        cin >> m;
        while (m-->0)
        {
            int w, d, t, o;
            cin >> w >> d >> t >> o;
            G[i].push_back({w, d, t, o});
        }
        
        distances[i] = INT_MAX;
    }

    distances[1] = 0;
    priority_queue<pair<int,int>> q;
    q.push({-0,1});
    while (!q.empty()){
        int t = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (t > distances[v]) continue;
        distances[v] = t;
        for (edge e : G[v]){
            int mod = (e.t-t)%e.o;
            if (mod < 0) mod += e.o;
            q.push({-(mod+e.d+t), e.w});
        }
    }
    if (distances[n] == INT_MAX){
        cout <<"ARESZT\n";
    }
    else {
        cout << distances[n] << '\n';
    }

    return 0;
}
/*
5
2
4 10 0 7
3 1 1 7
0
1
2 7 12 55
2
5 3 3 10
5 2 1 100
0
*/