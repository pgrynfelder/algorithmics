#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

vector<int> FU;
vector<int> FU_vertices;
unordered_set<int> unions;

int f(int x){
    if (FU[x] == x){
        return x;
    }
    FU[x] = f(FU[x]);
    return FU[x];
}
void u(int a, int b){
    if (FU_vertices[f(a)] > FU_vertices[f(b)]){ // pin b to a
        FU_vertices[f(a)] += FU_vertices[f(b)];
        FU_vertices[f(b)] = 0;
        unions.erase(f(b));
        FU[f(b)] = f(a);
    } else { // pin a to b
        FU_vertices[f(b)] += FU_vertices[f(a)];
        FU_vertices[f(a)] = 0;
        unions.erase(f(a));
        FU[f(a)] = f(b);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    FU.resize(n+1);
    for (int v = 1; v <= n; v++){
        FU[v] = v;
        unions.insert(v);
    }
    FU_vertices.resize(n+1, 1);
    FU_vertices[0] = 0;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    stack<int> to_union;
    for (int v = 1; v <= n; v++){
        unordered_map<int, int> edges;
        for (int &u : G[v]){
            if (u != f(v)) edges[f(u)]++;
        }

        for (auto &c : unions){
            if (c != f(v) and FU_vertices[c] != edges[c]){
                to_union.emplace(c);
            }
        }
        
        while (!to_union.empty()){
            u(v, to_union.top());
            to_union.pop();
        }
    }
    priority_queue<int, vector<int>, greater<int>> q;
    int result = 0;
    for (int &v : FU_vertices){
        if (v != 0) { q.push(v); result++; }
    }
    cout << result << '\n';
    while (!q.empty()){
        cout << q.top() << ' ';
        q.pop();
    }
    return 0;
}
