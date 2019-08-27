#include<bits/stdc++.h>
using namespace std;

int FU[7007];

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
    int v, w, weight, i;
    bool is_in_mst = false;
    edge (int _v, int _w, int _weight, int _i){
        v = _v; w = _w; weight = _weight; i = _i;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<edge> v;
    for (int i = 0; i < m; i++){
        int p, k, w;
        cin >> p >> k >> w;
        v.push_back({p, k, w, i});
        FU[p] = p;
        FU[k] = k;
    }
    sort(v.begin(), v.end(), [&](const edge a, const edge b){return a.weight < b.weight;});
    for (int i = 0; i < v.size(); i++){
        int current_weight = v[i].weight;
        //cout << "current weed " << current_weight << '\n';
        //cout << i << ' ';
        int j = i;
        while (v[j].weight == current_weight){
            if (f(v[j].v) != f(v[j].w)){
                v[j].is_in_mst = true;
            }
            j++;
        }
        j = i;
        while (v[j].weight == current_weight){
            if (f(v[j].v) != f(v[j].w)){
                u(v[j].v, v[j].w);
            }
            j++;
        }
        j--;
        //cout << --j << '\n';
        i = j;
    }
    sort(v.begin(), v.end(), [&](const edge a, const edge b){return a.i < b.i;});
    for (auto xd : v){
        if (xd.is_in_mst){
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n";
        }
    }
    return 0;
}
