#include<bits/stdc++.h>
#define dist(a, b) min(abs(a.x - b.x), abs(a.y - b.y))
using namespace std;
constexpr unsigned int uinf = 4e9 + 7;

struct node {
	int i, x, y;
	node (int _i, int _x, int _y){
		i = _i; x = _x; y = _y;
	}
	void print(){
		cout << "i: " << i << " x: " << x << " y: " << y << "\n";
	}
};

int n;
vector<node> X, Y; // czy to sie nie spitoli dla rownych X czy Y???
vector<int> inX, inY; // wsm chyba nei

vector<unsigned int> dist;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	X.resize(n, node(0,0,0)); Y.resize(n, node(0,0,0)); inX.resize(n); inY.resize(n);
	dist.resize(n, uinf);
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		node xd(i, x, y);
		X[i] = xd;
		Y[i] = xd;
	}
	sort(X.begin(), X.end(), [&](const node a, const node b) {return (a.x == b.x and a.y < b.y) or a.x < b.x;});
	sort(Y.begin(), Y.end(), [&](const node a, const node b) {return (a.y == b.y and a.x < b.x) or a.y < b.y;});
	for (int i = 0; i < n; i++){
		inX[X[i].i] = i;
		inY[Y[i].i] = i;
	}
	// for (node v : X) v.print();
	dist[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0,0});
	while (!Q.empty()){
		int i = Q.top().second;
		node &v = X[inX[i]];
		Q.pop();
		if (inX[i]+1 < n){
			node &u = X[inX[i] + 1];
			if (dist[u.i] > dist[v.i] + dist(u, v)){
				dist[u.i] = dist[v.i] + dist(u, v);
				Q.push({dist(u, v), u.i});
			}
		} 
		if (inX[i]-1 >= 0){
			node &u = X[inX[i] - 1];
			if (dist[u.i] > dist[v.i] + dist(u, v)){
				dist[u.i] = dist[v.i] + dist(u, v);
				Q.push({dist(u, v), u.i});
			}
		}
		if (inY[i]+1 < n){
			node &u = Y[inY[i] + 1];
			if (dist[u.i] > dist[v.i] + dist(u, v)){
				dist[u.i] = dist[v.i] + dist(u, v);
				Q.push({dist(u, v), u.i});
			}
		}
		if (inY[i]-1 >= 0){
			node &u = Y[inY[i] - 1];
			if (dist[u.i] > dist[v.i] + dist(u, v)){
				dist[u.i] = dist[v.i] + dist(u, v);
				Q.push({dist(u, v), u.i});
			}
		}
		
	}
	cout << dist[n-1] << "\n";
	return 0;
}
