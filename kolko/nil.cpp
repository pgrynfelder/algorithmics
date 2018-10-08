#include<bits/stdc++.h>

using namespace std;

uint64_t val[1000007];
bool vis[1000007];
vector<uint32_t> G[1000007];
queue<uint32_t> Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    uint32_t n;
    cin >> n;

    for (uint32_t i = 1; i <= n; i++){
        cin >> val[i];
    }
    G[1].push_back(0);
    G[0].push_back(1);
    for (uint32_t i = 1; i < n; i++){
        uint32_t a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (uint32_t i = 1; i <= n; i++){
        if (G[i].size() == 1){ // is leaf!
            Q.emplace(i);
        }
    }

    while (!Q.empty()){
        uint32_t v = Q.front();
        Q.pop();
        if (vis[v]){
            continue;
        }
        uint32_t unvisited_children = 0;
        for (auto w : G[v]){
            if (!vis[w]){
                unvisited_children++;
            }
        }
        if (unvisited_children != 1){
            continue; // simply leave this vertex, gonna be back soon
        }
        vis[v] = 1;
        uint64_t hi = 0;
        for (auto w : G[v]){
            if (vis[w]){
                hi = max(hi, val[w]);
            }
            else {
                Q.push(w);
            }
        }
        val[v] += hi;
    }
    cout << val[1] << '\n';
	return 0;
}