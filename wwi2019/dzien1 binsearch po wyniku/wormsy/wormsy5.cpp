#include<bits/stdc++.h>

using namespace std;

int w, h, t = 0;
int G[2007][2007];

int bfs(){
    int minh = 2137;
    queue<pair<int, int>> S;
    S.push({1,h});
    while (!S.empty()){
        int x = S.front().first, y = S.front().second;
        S.pop();
        if (G[x][y] == t){
            continue;
        }
        G[x][y] = t;
        minh = min(minh, y);
        if (x == w+2) return minh;
        vector<pair<int,int>> candidates = {{x,y+1},{x+1,y},{x-1,y},{x,y-1}};
        for (auto nbh : candidates){
            if (G[nbh.first][nbh.second] != 2){
                S.push(nbh);
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    fill(&G[0][0], &G[2006][2006], 2);

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

    int result = bfs() - 1;
    // if (result < 0){
    //     cout << "NIE\n";
    // }
    // else {
    //     cout << result << '\n';
    // }
    cout << result << '\n';
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