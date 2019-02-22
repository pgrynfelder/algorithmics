#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool crossed(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy){
        int xd = 0;
	// CD x CA i CD x CB	
        if (((dx - cx)*(ay - cy) - (dy - cy)*(ax - cx)) * ((dx-cx)*(by-cy) - (dy-cy)*(bx-cx)) < 0){
                xd++;
        }
	// AB x AD i AB x AC
        if (((bx - ax)*(dy - ay) - (by - ay)*(dx - ax)) *  ((bx - ax)*(cy - ay) - (by - ay)*(cx - ax)) < 0){
                xd++;
        }
        return xd == 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
        ll ax, ay, bx, by, cx, cy, dx, dy;
	int n;
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
