/*
#graph
#integrity
#connectivity
#binsearch
#parallelbinsearch
*/
#include<bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 7;

struct edge {
    int t = 0, u = 0, v = 0;
} E[N];

int FU[N];
int FU_size[N];

int f(int v){
    if (v == FU[v]) return v;
    FU[v] = f(FU[v]);
    return FU[v];
}

void u(int u, int v){
    u = f(u); v = f(v);
    if (FU_size[u] > FU_size[v]) swap(u, v);
    FU_size[v] += FU_size[u];
    FU[u] = v;
}
void u(edge e){
    return u(e.u, e.v);
}


int n, m, q, L[N], R[N];
pair<int, int> Q[N];
int mid(int i){ 
    return (L[i] + R[i]) / 2; 
}
bool connected(int i){ 
    return f(Q[i].first) == f(Q[i].second); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        E[i] = {i, u, v}; // e.t == i in this task
    }
    for (int i = 1; i <= q; i++){
        cin >> Q[i].first >> Q[i].second;
        L[i] = 1;
        R[i] = m+1;
    }

    // parallel binsearch here
    bool run = true;
    vector<int> sorted;
    for (int i = 1; i <= q; i++) sorted.push_back(i);
    while (run){
        run = false;
        for (int i = 1; i <= n; i++){
            FU[i] = i;
            FU_size[i] = 1;
        }
        sort(sorted.begin(), sorted.end(), [&](const int a, const int b){return mid(a) < mid(b);});
        int j = 1;
        for (int i : sorted){
            while (j <= m and E[j].t <= mid(i)){
                u(E[j]);
                j++;
            }
            if (connected(i)){
                R[i] = mid(i);
            } else {
                L[i] = mid(i) + 1;
            }
            if (L[i] < R[i]) run = true;
        }
    }
    for (int i = 1; i <= q; i++){
        if (Q[i].first == Q[i].second){
            cout << "0\n";
        }
        else if (L[i] <= m){
            cout << L[i] << "\n";
        }
        else {
            cout << "+oo\n";
        }
    }
    return 0;
}


/*
6 5 4
1 2
2 4
3 5
4 3
3 2
2 3
1 5
1 4
2 6

4
4
2
+oo
*/