#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int FU[(int)1e6+7];
int n;

int f(int x){
    if (x == FU[x]) return x;
    FU[x] = f(FU[x]);
    return FU[x];
}
void u(int a, int b){
    FU[f(a)] = f(b);
}

int n, m;
struct edge {
    int v, w, weight;
    //bool is_in_mst = false;
    edge (int _v, int _w, int _weight){
        v = _v; w = _w; weight = _weight;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    ll result = 0;
    vector<edge> v;
    for (int i = 0; i < m; i++){
        int p, k, w;
        cin >> p >> k >> w;
        v.push_back({w, p, k});
        FU[p] = p;
        FU[k] = k;
    }
    sort(v.begin(), v.end(), [&](const edge a, const edge b){return a.weight > b.weight;});
    bool additional = false;
    
    return 0;
}
