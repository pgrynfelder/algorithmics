#include<bits/stdc++.h>

using namespace std;

int G[1007][1007][2]; // [0] for distance, [1] 1/0 for can visit
priority_queue<vector<int>> Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int h, w, endi, endj;
    cin >> w >> h;
    for (int i = 0; i < h; i++){
        string s;
        cin >> s;
        for (int j = 0; j < w; j++){
            if (s[j] == 'P'){
                G[i][j][0] = 0;
                Q.push({G[i][j][0], i, j});
            }
            else if (s[j] == 'W'){
                endi = i;
                endj = j;
                G[i][j][0] = 10000000;
            }
            else {
                G[i][j][0] = 10000000;
            }
            G[i][j][1] = (s[j] == '#') ? 0 : 1;
        }
    }
    int x = 0;
    while(!Q.empty() and x < 10){
        //x++;
        int d = -Q.top()[0], i = Q.top()[1], j = Q.top()[2];
        //cout << i << ' ' << j << '\n';
        Q.pop();
        
        if (i+1 < h and G[i+1][j][1] and G[i+1][j][0] - 1 > G[i][j][0]){
            G[i+1][j][0] = G[i][j][0] + 1;
            Q.push({-G[i][j][0]-1, i+1, j});
        }
        if (j+1 < w and G[i][j+1][1] and G[i][j+1][0] - 1 > G[i][j][0]){
            G[i][j+1][0] = G[i][j][0] + 1;
            Q.push({-G[i][j][0]-1, i, j+1});
        }
        if (i-1 >= 0 and G[i-1][j][1] and G[i-1][j][0] - 1 > G[i][j][0]){
            G[i-1][j][0] = G[i][j][0] + 1;
            Q.push({-G[i][j][0]-1, i-1, j});
        }
        if (j-1 >= 0 and G[i][j-1][1] and G[i][j-1][0] - 1 > G[i][j][0]){
            G[i][j-1][0] = G[i][j][0] + 1;
            Q.push({-G[i][j][0]-1, i, j-1});
        }

    }
    /*for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cout << G[i][j][0] << ' ';
        }
        cout << '\n';
    }*/
    if (G[endi][endj][0] == 10000000){
        cout << "NIE\n";
    }
    else {
        cout << G[endi][endj][0] << '\n';
    }
	return 0;
}