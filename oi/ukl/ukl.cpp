#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int current;
constexpr int N = 1007, M = 1007;
int visited[M][N];
bool rotated = false;

vector<pair<int, int>> G[M][N];

struct traverser {
    int x, y, dir; // 0 up 1 left 2 down 3 right
    int hit_count;
    bool fw(){
        if (hit_count >= 2){
            if (dir == 3) dir = 0;
            else if (dir == 1) dir = 2;
        }
        for (int i = 0; i < 4; i++){
            if (dir == 0){
                if (not visited[x][y+1]){
                    G[x][y].push_back({x,y+1}); 
                    G[x][y+1].push_back({x,y}); 
                    y++; 
                    visited[x][y] = 1;
                    return true;
                }
            }
            else if (dir == 2){
                if (not visited[x][y-1]){
                    G[x][y].push_back({x,y-1}); 
                    G[x][y-1].push_back({x,y}); 
                    y--; 
                    visited[x][y] = 1; 
                    return true;
                }
            }
            else if (dir == 1){
                if (not visited[x-1][y]){
                    G[x][y].push_back({x-1,y}); 
                    G[x-1][y].push_back({x,y}); 
                    x--; 
                    visited[x][y] = 1; 
                    return true;
                }
            }
            else if (dir == 3){
                if (not visited[x+1][y]){
                    G[x][y].push_back({x+1,y}); 
                    G[x+1][y].push_back({x,y}); 
                    x++; 
                    visited[x][y] = 1; 
                    return true;
                }
            }
            hit_count++;
            dir = (dir + 1) % 4;
        }
        return false;
    }
};

struct left_traverser {
    int x, y;
    bool fw(){
        if (not visited[x-1][y]){
            G[x][y].push_back({x-1,y}); 
            G[x-1][y].push_back({x,y}); 
            x--; 
            visited[x][y] = 1; 
            return true;
        }
        return false;
    }
};

struct right_traverser {
    int x, y;
    bool fw(){
        if (not visited[x+1][y]){
            G[x][y].push_back({x+1,y}); 
            G[x+1][y].push_back({x,y}); 
            x++; 
            visited[x][y] = 1; 
            return true;
        }
        return false;
    }
};

void prepare_visited(){
    for (int i = 0; i <= m+1; i++){
        visited[i][0] = visited[i][n+1] = 2;
    }
    for (int i = 0; i <= n+1; i++){
        visited[0][i] = visited[m+1][i] = 2;
    }
}

// void print_visited(){
//     for (int j = n+1; j >= 0; j--){
//         for (int i = 0; i <= m + 1; i++){
//             cout << (int)visited[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }


void dfs(const int &x, const int &y){
    for (auto u : G[x][y]){
        if (visited[u.first][u.second] != 2){
            visited[u.first][u.second] = 2;
            if (!rotated){
                cout << x << " " << y << " " << u.first << " " << u.second << "\n";
            }
            else {
                cout << y << " " << x << " " << u.second << " " << u.first << "\n";
            }
            dfs(u.first, u.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if (n & 1 or m & 1){
        if (k >= n + m - 2 and k <= n*m-1){
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n"; return 0;
        }
        if (!(m & 1)){ // if m is even
            swap(m, n);
            rotated = true;
        }
    }
    else { // both are even
        if (k >= n + m - 1 and k <= n*m-1){
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n"; return 0;
        }
    }
    prepare_visited();
    traverser a, b;
    a.y = b.y = (1+n)/2;
    int mid = (1+m)/2;
    a.x = b.x = mid;
    visited[a.x][a.y] = 1;
    a.dir = 0; b.dir = 2;
    
    while (current < k)
    {
        if (a.fw()){
            current++;
        }
        if (current >= k) break;
        if (b.fw()){
            current++;
        }
    }
    // print_visited();

    left_traverser l; right_traverser r;
    for (int j = 1; j <= n; j++){
        l.x = r.x = mid;
        l.y = r.y = j;
        while(l.fw()) continue;
        while(r.fw()) continue;
    }
    // print_visited();

    visited[1][1] = 2;
    dfs(1, 1);
    return 0;
}
