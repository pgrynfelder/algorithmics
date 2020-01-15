#include<bits/stdc++.h>
using namespace std;

constexpr long long N = 107, M = 1e6+7, K = 1e3+7;
bool composite[M];

void sieve(){
	composite[0] = composite[1] = true;	
	for (int k = 2; k < K; k++){
		if (composite[k]) continue;
		int i = 2*k;
		while (i < M){
			composite[i] = true;
			i += k;
		}
	}
		
}

struct room {
	int x, y, z;
	room (int _x, int _y, int _z){
		x = _x; y = _y; z = _z;
	}
	vector<room> neighbours(){
		return vector<room>{{x-1, y, z}, {x+1, y, z}, {x, y-1, z}, {x, y+1, z}, {x, y, z-1}, {x,y,z+1}};
	}
};

int T[N][N][N];
int D[N][N][N];

int n;


void bfs(room start){
	queue<room> Q;
	Q.push(start);
	D[start.x][start.y][start.z] = 0;
	T[start.x][start.y][start.z] = 1;
	while (!Q.empty()){
		room v = Q.front(); Q.pop();
		// cout << "v: " << v.x << " " << v.y << " " << v.z << "\n";
		for (room u : v.neighbours()){
			if (T[u.x][u.y][u.z] == 2){
				cout << D[v.x][v.y][v.z] + 1 << "\n";
				return;
			}
			if (T[u.x][u.y][u.z] == 0){
				T[u.x][u.y][u.z] = 1;
				D[u.x][u.y][u.z] = D[v.x][v.y][v.z] + 1;
				Q.push(u);
			}
		}
	}
	cout << "0\n";
}		

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	
	cin >> n;
	room start(0,0,0);
	for (int x = 1; x <= n; x++){
		for (int y = 1; y <= n; y++){
			for (int z = 1; z <= n; z++){
				int c;
				cin >> c;
				if (c == 0){
					start.x = x; start.y = y; start.z = z;
					// cout << "start: " << start.x << start.y << start.z << "\n";
				}
				T[x][y][z] = composite[c];
			}
		}
	}
	
	for (int x = 0; x <= n+1; x++){
		for (int y = 0; y <= n+1; y++){
			T[x][y][0] = T[x][y][n+1] = T[x][0][y] = T[x][n+1][y] = T[0][x][y] = T[n+1][x][y] = 2;
		}
	}	
	bfs(start);	
	return 0;	
}
/*
3
3 5 7
6 4 9
2 3 4
4 8 6
4 0 3
1 4 6
4 6 9
3 7 2
5 3 5
*/
