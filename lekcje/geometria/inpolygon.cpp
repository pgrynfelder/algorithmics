#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int sgn(ll x){
	if (x > 0) return 1;
	if (x == 0) return 0;
	else return -1;
}

int crossed(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy){
	// CD x CA i CD x CB	
	int pro1 = sgn((dx - cx)*(ay - cy) - (dy - cy)*(ax - cx));
	int pro2 = sgn((dx - cx)*(by - cy) - (dy - cy)*(bx - cx));
	// AB x AC i AB x AD
	int pro3 = sgn((bx - ax)*(cy - ay) - (by - ay)*(cx - ax));
	int pro4 = sgn((bx - ax)*(dy - ay) - (by - ay)*(dx - ax));
	
	if(pro1*pro2 < 0 and pro3*pro4 < 0) return 1;
	if(pro1*pro2 == 0 and pro3*pro4 == 0){
		if (((ax - cx)*(bx - cx) + (ay - cy)*(by - cy) <= 0) or ((ax - dx)*(bx - dx) + (ay - dy)*(by - dy) <= 0))  return 1;
		else return 0;
	}
	if (pro1 == 0){
		if ((cx - ax)*(dx - ax) + (cy - ay)*(dy - ay) <= 0) return 2;
	}
	if (pro2 == 0){
		if ((cx - bx)*(dx - bx) + (cy - by)*(dy - by) <= 0) return 2;
	}
	if (pro3 == 0){
		if ((ax - cx)*(bx - cx) + (ay - cy)*(by - cy) <= 0) return 2;
	}
	if (pro4 == 0){
		if ((ax - dx)*(bx - dx) + (ay - dy)*(by - dy) <= 0) return 2;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    vector<pair<int, int>> nodes;
	int n, m;
	cin >> n;
	while (n-->0){
		int x, y;
		cin >> x >> y;
		nodes.push_back({x,y});
	}
	cin >> m;
	while (m-->0){
		int px, py, ix, iy, crossings = 0;
		cin >> px >> py;
		ix = INT_MAX; 
		iy = py + 1;
		int result;
		for (int i = 0; i < nodes.size(); i++){
			int ax = nodes[i].first, 
				ay = nodes[i].second, 
				bx = nodes[(i+1)%nodes.size()].first, 
				by = nodes[(i+1)%nodes.size()].second;
			result = crossed(ax, ay, bx, by, px, py, ix, iy);
			if (result == 2){
				cout << "KRAWEDZ\n";
				break;
			}
			if (result == 1){
				crossings++;
			}
		}
		if (result != 2 and crossings & 1 == 1){
			cout << "WEWNATRZ\n";
		} else if (result != 2){
			cout << "NA ZEWNATRZ\n";
		}
	}
	return 0;
}
