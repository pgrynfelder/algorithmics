#include<bits/stdc++.h>

using namespace std;

int w, h, t;
int G[2007][2007];

bool bfs(){
    queue<pair<int,int>> Q;
    
    cout << "is Q empty? " << Q.empty() << "\n";
    Q.push({1, h});
    while (!Q.empty()){
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        if (G[x][y] == t){
            continue;
        }
        G[x][y] = t;
        vector<pair<int,int>> candidates = {{x,y+1},{x,y-1},{x-1,y},{x+1,y}};
        for (auto nbh : candidates){
            if (G[nbh.first][nbh.second] != 2137 and nbh.second >= t){
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
        if (bfs()){
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
    fill(&G[0][0], &G[2007][2007], 2137);

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
    
    int result = bs(0,2007);
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