#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int current;
constexpr int N = 1007, M = 1007;
bool visited[M][N];
bool rotated = false;

vector<pair<int, int>> G[M][N];

struct traverser {
    int x, y, dir; // 0 up 1 left 2 down 3 right
    bool filling;
    bool fw(){
        for (int i = 0; i < 4; i++){
            if (dir == 0){
                if (!visited[x][y+1]){
                    G[x][y].push_back({x,y+1}); 
                    G[x][y+1].push_back({x,y}); 
                    y++; 
                    visited[x][y] = true; 
                    if (x == 0 or )
                    return true;
                }
            }
            else if (dir == 2){
                if (!visited[x][y-1]){
                    G[x][y].push_back({x,y-1}); 
                    G[x][y-1].push_back({x,y}); 
                    y--; 
                    visited[x][y] = true; 
                    return true;
                }
            }
            else if (dir == 1){
                if (!visited[x-1][y]){
                    G[x][y].push_back({x-1,y}); 
                    G[x-1][y].push_back({x,y}); 
                    x--; 
                    visited[x][y] = true; 
                    return true;
                }
            }
            else if (dir == 3){
                if (!visited[x+1][y]){
                    G[x][y].push_back({x+1,y}); 
                    G[x+1][y].push_back({x,y}); 
                    x++; 
                    visited[x][y] = true; 
                    return true;
                }
            }
            dir = (dir + 1) % 4;
        }
        return false;
    }
};

void prepare_visited(){
    for (int i = 0; i <= m+1; i++){
        visited[i][0] = visited[i][n+1] = true;
    }
    for (int i = 0; i <= n+1; i++){
        visited[0][i] = visited[m+1][i] = true;
    }
}

void print_visited(){
    for (int j = n+1; j >= 0; j--){
        for (int i = 0; i <= m + 1; i++){
            cout << (int)visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if (n & 1 or m & 1){
        if (k >= n + m - 1 and k <= n*m-1){
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n"; return 0;
        }
        if (!(m & 1)){ // if m is even
            swap(m, n);
            rotated = true;
        }
        prepare_visited();
        traverser a, b;
        a.y = b.y = (1+n)/2;
        a.x = b.x = (1+m)/2;
        visited[a.x][a.y] = true;
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
        // cout << "a: " << a.x << " " << a.y << "; b: " << b.x << " " << b.y << "\n";
        print_visited();
    }
    else { // both are even

    }
    print_visited();
    return 0;
}
