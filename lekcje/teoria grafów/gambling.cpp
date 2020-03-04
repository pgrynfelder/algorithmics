#include<bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 7, M = 3e5 + 7;
constexpr double inf = INFINITY;
double E[N];
int calculated[N];
int calculated_count[N];
double calculated_sum[N];
vector<int> G[N];
int n, m;

void update_E(int v){
    E[v] = (G[v].size() + calculated_sum[v])/calculated_count[v];
    // because
    // E(v) = 1 + (smaller_sum + bigger_count * E(v)) / deg(v)
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i < n; i++){
        E[i] = inf; // E[n] = 0
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
    
    Q.emplace(0, n);

    while (!Q.empty()){
        double e = Q.top().first;
        int v = Q.top().second;
        Q.pop();
        if (calculated[v]) continue;
        calculated[v] = true;
        for (int u : G[v]){
            if (!calculated[u]){
                calculated_count[u]++;
                calculated_sum[u] += E[v];
                update_E(u);
                Q.emplace(E[u], u);
            }
        }
    }
    cout << fixed << setprecision(7) << E[1];
    return 0;
}

/*

5 8
1 2
1 3
1 4
2 3
2 4
3 5
5 4
2 5

4.11111111
*/