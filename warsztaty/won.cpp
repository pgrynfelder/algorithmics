#include<bits/stdc++.h>

using namespace std;

int T[1007][1007];

queue<pair<int, int>> Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int maxresult = 0;
	cin >> n;

	for (int x = 0; x < n; x++){
		string row;
		cin >> row;
		for (int y = 0; y < n; y++){
			if (row[y] == '.'){
				 T[x][y] = 0;
			} else if (row[y] == '+'){
				 T[x][y] = 2;
			} else {
				T[x][y] = -1;		
			}
		}
	}
	
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			Q.push(pair<int,int>(x, y));
			int result = 0;
			while(!Q.empty()){
				pair<int, int> v = Q.front();
				Q.pop();
				int i = v.first; 
				int j = v.second;
				
				if (T[i][j] == -1) continue;
				if (T[i][j] == 1) continue;
				if (T[i][j] == 2) result++;
				T[i][j]=1;
				Q.push(pair<int,int>((i-1+n)%n, j));
				Q.push(pair<int,int>((i+1+n)%n, j));
				Q.push(pair<int,int>(i, (j-1+n)%n));
				Q.push(pair<int,int>(i, (j+1+n)%n));
				// cout << "petlanaszyi\n";
			}
			// cout<< result << endl;
			maxresult = max(maxresult, result);
		}	
	}
	cout << maxresult << "\n";
	return 0;
}