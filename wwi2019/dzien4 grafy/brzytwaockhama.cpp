#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G1;
vector<vector<int>> G2;
vector<vector<int>> G3;
vector<int> sorted;
vector<int> comp;
vector<int> comp_e;
vector<bool> visited;
vector<int> D;

void dfspo(int v){
    for (auto u : G1[v]){
        if (!visited[u]){
            visited[u] = 1;
            dfspo(u);
        }
    }
    sorted.push_back(v);
}

void dfs(int v){
    for (int u : G2[v]){
        if (comp[u] == comp[v]){
           comp_e[comp[v]]++;
        } else if (comp[u] == 0){
           comp[u] = comp[v];
           comp_e[comp[v]]++;
           dfs(u);
        } else {
            G3[comp[u]].push_back(comp[v]);
            //G3[comp[v]].push_back(comp[u]); // -make a transponed G3 for dynamic solution
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    G1.resize(n+1);
    G2.resize(n+1);
    G3.resize(n+1);
    visited.resize(n+1);
    comp.resize(n+1);
    comp_e.resize(n+1);
    D.resize(n+1);

    for (int i = 0; i < m; i++){   
        int a, b;
        cin >> a >> b;
        G1[a].push_back(b);
        G2[b].push_back(a);
    }

    for (int v = 1; v <= n; v++){
        if (!visited[v]){
            visited[v] = true;
            dfspo(v);
        }
    }
    reverse(sorted.begin(), sorted.end());
    int i = 1;
    for (int v : sorted){
        if (comp[v] == 0){
            comp[v] = i;
            dfs(v);
            i++;
        }
    }
    while (i-->1){
        D[i] = comp_e[i];
        
        int biggest = 0;
        for (int v : G3[i]){
            biggest = max(biggest, D[v] + 1);
        }
        D[i] += biggest;
    }

    for (int v = 1; v <= n; v++){
        cout << D[comp[v]] << '\n';
    }

    return 0;
}
/*
7 7
1 2
2 1
2 3
3 4
4 5
4 6
6 7
*/