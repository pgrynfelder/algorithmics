#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M_MAX = 1e6 + 7;

int FU[M_MAX];
bool medusa[M_MAX];
int n;

int f(int x){
    if (x == FU[x]) return x;
    FU[x] = f(FU[x]);
    return FU[x];
}
void u(int a, int b){
    FU[f(a)] = f(b);
}

struct edge {
    int v = 0, w = 0, weight = 0;
    edge (int _v, int _w, int _weight){
        v = _v; w = _w; weight = _weight;
    }
    edge(){};
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    ll result = 0;
    vector<edge> v(n);
    for (int i = 0; i < n; i++){
        int p, k, w;
        cin >> w >> p >> k;
        v[i] = edge(p, k, w);
        FU[p] = p;
        FU[k] = k;
        result += w;
    }
    sort(v.begin(), v.end(), 
    [&](const edge a, const edge b){return a.weight > b.weight;});
    for (auto e : v){
        if (f(e.v) == f(e.w)){
            if (!medusa[f(e.v)]){
                medusa[f(e.v)] = 1;
                result -= e.weight;
            }
        }
        else {
            if (medusa[f(e.v)] and medusa[f(e.w)]){
                continue;
            }
            else if (medusa[f(e.v)] or medusa[f(e.w)]){ // can replace xor with or because and's already checked
                u(e.v, e.w);
                medusa[f(e.v)] = 1;
                result -= e.weight;        
            }
            else {
                u(e.v, e.w);
                result -= e.weight;
            }
        }
    }
    cout << result << '\n';
    return 0;
}
