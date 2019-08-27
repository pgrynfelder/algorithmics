#include<bits/stdc++.h>

using namespace std;

int w, h, t;
int G[2007][2007];

bool dfs(){
    stack<pair<int,int>> Q;
    
    Q.push({1, h});
    while (!Q.empty()){
        int x = Q.top().first, y = Q.top().second;
        Q.pop();
        if (G[x][y] == t){
            continue;
        }
        G[x][y] = t;
        vector<pair<int,int>> candidates = {{x-1,y},{x,y-1},{x+1,y},{x,y+1}};
        for (auto nbh : candidates){
            if (G[nbh.first][nbh.second] != 2137 and G[nbh.first][nbh.second] != t and nbh.second >= t){
                Q.push(nbh);
            }
        }
    }
    return G[w+2][h] == t;
}

int bs(int l, int r){
    while (l < r){
        int mid = (l+r)/2;
        t = mid;
        if (dfs()){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    fill(&G[0][0], &G[2006][2006], 2137);

    for (int y = h; y >= 1; y--){
        string s;
        cin >> s;
        for (int x = 2; x <= w+1; x++){
            if (s[x-2] == '.'){
                G[x][y] = -1;
            }
        }
    }
    for (int y = 1; y <= h; y++){
        G[1][y] = -1;
        G[w+2][y] = -1;
    }

    int result = bs(0,2007) - 2;
    if (result < 0){
        cout << "NIE\n";
    }
    else {
        cout << result << '\n';
    }
    
    return 0;
}

/*

5 6
#...#.
..##..
#....#
##...#

*/
