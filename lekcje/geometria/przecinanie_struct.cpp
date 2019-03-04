#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int sgn(ll x){
	if (x > 0) return 1;
	if (x == 0) return 0;
	else return -1;
}

struct v {
	int x, y;
	v (){
		x = 0; y = 0;
	}
	v (int _x, int _y){
		x = _x; y = _y;
	}
	v operator+ (){
		return *this;
	}
	v operator+ (v other){
		return v(this->x+other.x, this->y+other.y);
	}
	v operator- (){
		return v(-this->x, -this->y);
	}
	v operator- (v other){
		return *this + (-other);
	}
	ll operator^ (v other){ // cross product
		return (ll)this->x * other.y - (ll)this->y * other.x;
	}
	ll operator* (v other){ // dot product
		return (ll)this->x * other.x + (ll)this->y * other.y;
	}
};

bool crossed(v a, v b, v c, v d){
	int pro1 = sgn((d - c)^(a - c));
	int pro2 = sgn((d - c)^(b - c));
	int pro3 = sgn((b - a)^(c - a));
	int pro4 = sgn((b - a)^(d - a));
	if(pro1*pro2 < 0 and pro3*pro4 < 0) return true;
	if (pro1 == 0){ // CD || CA => A lies on line CD
		if ((c - a)*(d - a) <= 0) return true;
	}
	if (pro2 == 0){ // CD || CB => B lies on line CD
		if ((c - b)*(d - b) <= 0) return true;
	}
	if (pro3 == 0){ // AB || AC => C lies on line AB
		if ((a - c)*(b - c) <= 0) return true;
	}
	if (pro4 == 0){ // AB || AD => D lies on line AB
		if ((a - d)*(b - d) <= 0) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    v a, b, c, d;
	int n;
	cin >> n;
	while (n-->0){
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		if (crossed(a, b, c, d)){
			cout << "TAK\n";
		}
		else {
			cout << "NIE\n";
		}
	}
	return 0;
}
