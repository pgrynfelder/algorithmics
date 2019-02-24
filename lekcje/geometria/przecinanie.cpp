#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool crossed(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy){
    int xd = 0;
	// CD x CA i CD x CB	
	ll pro1 = ((dx - cx)*(ay - cy) - (dy - cy)*(ax - cx)) * ((dx-cx)*(by-cy) - (dy-cy)*(bx-cx));
	cout << pro1 << "\n";
	// AB x AD i AB x AC
	ll pro2 = ((bx - ax)*(dy - ay) - (by - ay)*(dx - ax)) *  ((bx - ax)*(cy - ay) - (by - ay)*(cx - ax));
	cout << pro2 << "\n";

	if(pro1 < 0 and pro2 < 0) return true;
	if(pro1 == 0 and pro2 == 0) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
        ll ax, ay, bx, by, cx, cy, dx, dy;
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
