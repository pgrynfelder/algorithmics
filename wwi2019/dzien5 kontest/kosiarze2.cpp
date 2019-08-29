#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+7;
int FU[N];
int FU_MAXEDGE[N];

vector<edge> G[N];
struct edge {
    int v, weight;
    edge (int _v, int _weight){
        v = _v;
        weight = _weight;
    }
};
int f(int x){
    if (x == FU[x]) return x;
    FU[x] = f(FU[x]);
    return FU[x];
}
void u(int a, int b){
    FU_MAXEDGE[f(b)] = max(FU_MAXEDGE[f(b)], FU_MAXEDGE[f(a)]);
    FU[f(a)] = f(b);
}

class compare {
    public:
    bool operator() (edge a, edge b){
        return a.weight > b.weight;
    }
};

int n, m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> FU_MAXEDGE[i];
    }

    for (int i = 1; i <= m; i++){
        int a, b, w;
        G[a].push_back(edge(b, w));
        G[b].push_back(edge(a, w));
    }

    priority_queue<edge, vector<edge>, compare> Q;
    for (auto e : G[1]){
        Q.push(e);
    }
    while (!Q.empty()){
        edge e = Q.top();
        Q.pop();
        
    }

    
    return 0;
}
