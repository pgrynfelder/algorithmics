#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> degin;
vector<int> input1;
vector<int> input2;
vector<bool> visited;
int n, m;
bool cycle(int t){
    for (int i = 1; i <= n; i++){
        degin[i] = 0;
        visited[i] = 0;
        G[i].clear();
    }
    for (int i = 0; i < t; i++){
        G[input1[i]].push_back(input2[i]);
        degin[input2[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (degin[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int v = q.front();
        q.pop();
        if (visited[v]) continue;
        visited[v] = 1;
        for (int w : G[v]){
            degin[w]--;
            if (degin[w] == 0) q.push(w);
        }
        G[v].clear();
    }
    for (int i = 1; i <= n; i++){
        if (!G[i].empty()) return true;
    }
    return false;
}

int bs(int l, int r){
	while (l < r){
		int mid = (l+r)/2;

		if (cycle(mid) == true){
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
    cin >> n >> m;

    G.resize(n+1);
    degin.resize(n+1);
    input1.resize(m);
    input2.resize(m);
    visited.resize(n+1);
    for (int i = 0; i < m; i++){
        cin >> input1[i] >> input2[i];        
    }
    int result = bs(0, m+1);
    if (result > m){
        cout << "NIE\n";
    }
    else {
        cout << result << '\n';
    }
    return 0;
}
// nie dziala