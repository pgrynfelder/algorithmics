#include<bits/stdc++.h>

using namespace std;

int w, h, t;

vector<pair<int,int>> valid_nbh(pair<int,int> u){
    int x = u.first;
    int y = u.second;
    vector<pair<int,int>> candidates = {{x+1,y}, {x-1, y}, {x,y+1}, {x, y-1}};
    vector<pair<int,int>> result;
    for (auto c : candidates){
            if (c.first < w and c.first >= 0 and c.second < h and c.second >= t){
                result.push_back(c);
            }
    }
    return result;
}
bool bfs(vector<vector<bool>> &G){
    vector<vector<bool>> passable = G;
    queue<pair<int, int>> Q;
    int sx = 0;
    for (int sy = 0; sy < h; sy++){
        if (passable[sx][sy]){
            Q.push({sx,sy});
        }
        while (!Q.empty()){
            auto u = Q.front();
            Q.pop();
            if (!passable[u.first][u.second]) continue;
            passable[u.first][u.second] = false;
            if (u.first == w-1){
                return true;
            }
            for (auto c : valid_nbh(u)){
                Q.push(c);
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    
    vector<vector<bool>> G(w, vector<bool>(h, 0));
    for (int y = h-1; y >= 0; y--){
        string s;
        cin >> s;
        for (int x = 0; x < w; x++){
            if (s[x] == '.'){
                G[x][y] = true;
            }
        }
    }
    t = 0;
    //cout << bs(0,2000,G)-1 << '\n';
    int result = bs(0,2000,G);
    if (result == -1){
        cout << "NIE\n";
    }
    else {
        cout << result << '\n';
    }
    //cout << bfs(G) << '\n';
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