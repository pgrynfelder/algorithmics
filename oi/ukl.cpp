
#include<bits/stdc++.h>
using namespace std;


int n, m, k;
constexpr int N = 1007, M = 1007;
bool visited[M][N];
bool rotated = false;

vector<pair<int, int>> G[M][N];

struct traverser {
    int x, y, dir; // 0 up 1 left 2 down 3 right
    bool fw(){
        for (int i = 0; i < 4; i++){
            if (dir == 0){
                if (!visited[x][y+1]){
                    y++; return true;
                }
            }
            else if (dir == 2){
                if (!visited[x][y-1]){
                    y--; return true;
                }
            }
            else if (dir == 1){
                if (!visited[x-1][y]){
                    x--; return true;
                }
            }
            else if (dir == 3){
                if (!visited[x+1][y]){
                    x++; return true;
                }
            }
            dir = (dir + 1) % 4;
        }
        return false;
    }
};

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
        traverser a, b;

    }
    else { // both are even

    }
    return 0;
}
