#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int sgn(ll x){
	if (x > 0) return 1;
	if (x == 0) return 0;
	else return -1;
}

bool crossed(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy){
	// CD x CA i CD x CB	
	int pro1 = sgn((dx - cx)*(ay - cy) - (dy - cy)*(ax - cx));
	int pro2 = sgn((dx - cx)*(by - cy) - (dy - cy)*(bx - cx));
	//cout << pro1 << " " << pro2 << "\n";
	// AB x AC i AB x AD
	int pro3 = sgn((bx - ax)*(cy - ay) - (by - ay)*(cx - ax));
	int pro4 = sgn((bx - ax)*(dy - ay) - (by - ay)*(dx - ax));
	//cout << pro3 << " " << pro4 << "\n";

	if(pro1*pro2 < 0 and pro3*pro4 < 0) return true;
	if(pro1*pro2 == 0 and pro3*pro4 == 0){
		if (((ax - cx)*(bx - cx) + (ay - cy)*(by - cy) <= 0) or ((ax - dx)*(bx - dx) + (ay - dy)*(by - dy) <= 0))  return true;
		else return false;
	}
	if (pro1 == 0){
		if ((cx - ax)*(dx - ax) + (cy - ay)*(dy - ay) <= 0) return true;
	}
	if (pro2 == 0){
		if ((cx - bx)*(dx - bx) + (cy - by)*(dy - by) <= 0) return true;
	}
	if (pro3 == 0){
		if ((ax - cx)*(bx - cx) + (ay - cy)*(by - cy) <= 0) return true;
	}
	if (pro4 == 0){
		if ((ax - dx)*(bx - dx) + (ay - dy)*(by - dy) <= 0) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int ax, ay, bx, by, cx, cy, dx, dy;
	int n;
	cin >> n;
	while (n-->0){
		cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
		if (crossed(ax,ay,bx,by,cx,cy,dx,dy)){
			cout << "TAK\n";
		}
		else {
			cout << "NIE\n";
		}
	}
	return 0;
}
