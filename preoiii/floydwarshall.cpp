#include<bits/stdc++.h>
using namespace std;

constexpr int N = 507;
constexpr double inf = INFINITY;
int n, m;

double dist[N][N];
double dist2[N][N];

void fw(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist2[i][j] = dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void fw2(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j) dist[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if (a != b) dist[a][b] = w;
    }
    fw();
    fw2();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dist[i][j] == inf)
                cout << "* ";
            else if (dist[i][j] != dist2[i][j] or dist[i][j] == -inf){
                cout << "-oo ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
                
    
