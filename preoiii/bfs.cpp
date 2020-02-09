#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6;

vector<int> G[N];
bool visited[N];

void bfs(int v){
    queue<int> Q;
    visited[v] = 1;
    Q.push(v);
    while (!Q.empty()){
        v = Q.front(); Q.pop();
        for (int u : G[v]){
            if (!visited[u]){
                visited[u] = 1;
                Q.push(u);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
}

