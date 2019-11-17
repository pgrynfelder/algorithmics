#include<bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1007;
vector<pair<int, int>> G[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int nodes = 0;
void dfs(pair<int, int> v) {
    nodes++;
    for (auto u : G[v.first][v.second]){
        if (dist[u.first][u.second] == -1){
            dist[u.first][u.second] = dist[v.first][v.second] + 1;
            dfs(u);
        }
    }
}
int n, m, k;

pair<int, int> find_max(){
    pair<int, int> maxc;
    int maxv = INT_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (dist[i][j] > maxv){
                maxv = dist[i][j];
                maxc = {i, j};
            }
        }
    }
    return maxc;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n * m - 1; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!(1 <= a and a <= n and 1 <= b and b <= m and 1 <= c and c <= n and 1 <= d and d <= m)){
            cout << a << " " << b << " " << c << " " << d << "\n";
            cout << "BŁĄD: INDEX OUT OF BOUNDS\n";
            return 0;
        }
        G[a][b].push_back({c, d});
        G[c][d].push_back({a, b});
    }

    // while (getline(cin, s))
    // {   
    //     if (s.size()){
    //         cout << "BŁĄD: SYF NA OUTPUCIE\n";
    //         return 0;
    //     }
    // }
    fill(&(dist[0][0]), &(dist[MAX_N-1][MAX_N-1]), -1);
    dist[1][1] = 0;
    dfs(pair<int, int>(1, 1));
    if (nodes != n*m){
        cout << "TOO LITTLE NODES\n";
    }
    auto maxx = find_max();
    fill(&(dist[0][0]), &(dist[MAX_N-1][MAX_N-1]), -1);
    dist[maxx.first][maxx.second] = 0;
    dfs(maxx);
    maxx = find_max();
    if (dist[maxx.first][maxx.second] != k){
        cout << "BAD DIAMETER\n";
    }
    cout << "GITUWA\n";
    return 0;
}
