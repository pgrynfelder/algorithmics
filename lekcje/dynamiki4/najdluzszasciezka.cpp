#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5+7;
int p[N];
vector<int> G[N];
int dist[N];

void dfs(int v){
    //cout << v << ' ';
    for (int u : G[v]){
        if (u != p[v]){
            p[u] = v;
            dist[u] = dist[v] + 1;
            dfs(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dist[1] = 0;
    dfs(1); //cout << '\n';
    int maxdist = -1;
    int maxv = 0;
    for (int i = 1; i <= n; i++){
        p[i] = 0;
        if (dist[i] > maxdist){
            maxdist = dist[i];
            maxv = i;
        }
    }

    dist[maxv] = 0;
    dfs(maxv); //cout << '\n';
    for (int i = 1; i <= n; i++){
        if (dist[i] > maxdist){
            maxdist = dist[i];
            maxv = i;
        }
    }
    cout << maxdist << '\n';

    while (v != 0){
        cout << v << ' ';
        v = p[v];
    }
    /*
    int v = maxv;
    stack<int> result;
    while (v != 0){
        result.push(v);
        v = p[v];
    }
    cout << result.size() - 1 << '\n';
    while (!result.empty()){
        cout << result.top() << ' ';
        result.pop();
    }
    */
    return 0;
}

