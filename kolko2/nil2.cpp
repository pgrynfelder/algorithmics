#include<bits/stdc++.h>

using namespace std;

bitset<1000007> visited;
vector<uint32_t> children[1000007];
vector<uint32_t> G[1000007];
stack<uint32_t> S;
uint64_t val[1000007];

void dfs(uint32_t v){
    visited[v] = true;
    S.push(v);
    for (auto w : G[v]){
        if (!visited[w]){
            dfs(w);
            children[v].push_back(w);
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    uint32_t n;
    cin >> n;

    for (uint32_t i = 1; i <= n; i++){
        cin >> val[i];
    }
    
    for (uint32_t i = 1; i < n; i++){
        uint32_t a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // topo sort with dfs
    dfs(1);

    while(!S.empty()){
        uint32_t v = S.top();
        S.pop();
        uint64_t hi = 0;
        for (uint32_t w : children[v]){
            hi = max(hi, val[w]);
        }
        val[v] += hi;
    }
    cout << val[1] << '\n'; 
}