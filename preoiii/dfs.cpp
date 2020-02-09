#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6;

vector<int> G[N];
bool visited[N];

void dfs(int v){
    cout << v << "\n"; // pre order
    for (int u : G[v]){
        if (!visited[u]){
            visited[u] = 1;
            dfs(u);
        }
    }
    cout << v << "\n"; // post order
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
}
