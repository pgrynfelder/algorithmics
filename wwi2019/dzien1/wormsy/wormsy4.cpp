#include<bits/stdc++.h>

using namespace std;

int w, h, V = 0, W = 2;
int G[2007][2007];

int minh = 2137;

bool continuedfs = true;

void dfs(int x, int y){
    if (!continuedfs) return;
    if (G[x][y] == V){
        return;
    }
    G[x][y] = V;
    minh = min(minh, y);
    if (x == w+2) {cout << "\n" << x << ' ' << y << "\n"; continuedfs = false;}
    if (G[x][y+1] != W) dfs(x, y + 1); 
    if (G[x+1][y] != W) dfs(x + 1, y); 
    if (G[x][y-1] != W) dfs(x, y - 1);
    if (G[x-1][y] != W) dfs(x - 1, y);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    fill(&G[0][0], &G[2006][2006], W);

    for (int y = h; y >= 1; y--){
        string s;
        cin >> s;
        for (int x = 2; x <= w+1; x++){
            if (s[x-2] == '.'){
                G[x][y] = 1;
            }
        }
    }
    for (int y = 1; y <= h; y++){
        G[1][y] = 1;
        G[w+2][y] = 1;
    }
    dfs(1, h);
    int result = minh;
    if (result < 0){
        cout << "NIE\n";
    }
    else {
        cout << result << '\n';
    }
    for (int y = h + 1; y >= 0; y--){
        for (int x = 0; x <= w+3; x++){
            cout << G[x][y] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

/*

5 6
#...#.
..##..
#....#
##...#
##..##

*/