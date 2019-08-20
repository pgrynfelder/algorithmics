#include<bits/stdc++.h>

using namespace std;

struct nbh {
    int i;
    int t;
};

vector<vector<nbh>> G;
vector<int> visited;
int t;

bool dfs(int u){
    visited[u] = 1;
    for (nbh v : G[u]){
        if (v.t <= t){
            if (visited[v.i] == 1){
                return true;
            }
            if (dfs(v.i) == true){
                return true; 
            }
        }
    }
    visited[u] = 2;
    return false;
}

bool cycle(){
    for (int u = 1; u < visited.size(); u++){
        if (visited[u] == 0){
            if (dfs(u)) return true;
        }
    }
    return false;
}


int bs(int l, int r){
	while (l < r){
		int mid = (l+r)/2;
        t = mid;
		if (cycle() == true){
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    G.resize(n+1);
    visited.resize(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back({b, i});
        
    }
    
    cout << bs(0, n+1) << '\n';
    return 0;
}
// nie dziala