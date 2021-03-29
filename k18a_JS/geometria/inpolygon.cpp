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

int crossed(v a, v b, v c, v d){
	int pro1 = sgn((d - c)^(a - c));
	int pro2 = sgn((d - c)^(b - c));
	int pro3 = sgn((b - a)^(c - a));
	int pro4 = sgn((b - a)^(d - a));
	if(pro1*pro2 < 0 and pro3*pro4 < 0) return 1;
	if (pro1 == 0){ // CD || CA => A lies on line CD
		if ((c - a)*(d - a) <= 0) return 2;
	}
	if (pro2 == 0){ // CD || CB => B lies on line CD
		if ((c - b)*(d - b) <= 0) return 2;
	}
	if (pro3 == 0){ // AB || AC => C lies on line AB
		if ((a - c)*(b - c) <= 0) return 2;
	}
	if (pro4 == 0){ // AB || AD => D lies on line AB
		if ((a - d)*(b - d) <= 0) return 2;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    vector<v> nodes;
	int n, m;
	cin >> n;
	while (n-->0){
		v v1;
		cin >> v1.x >> v1.y;
		nodes.push_back(v1);
	}
	cin >> m;
	while (m-->0){
		v p, inf;
		int crossings = 0;
		cin >> p.x >> p.y;
		inf.x = 1e9+1; 
		inf.y = p.y + 1;
		int result;
		for (int i = 0; i < nodes.size(); i++){
			v a = nodes[i];
			v b = nodes[(i+1)%nodes.size()];
			result = crossed(a, b, p, inf);
			if (result == 2){
				cout << "KRAWEDZ\n";
				break;
			}
			if (result == 1){
				crossings++;
			}
		}
		if (result != 2){
			if(crossings & 1 == 1){
			cout << "WEWNATRZ\n";
			} else {
			cout << "NA ZEWNATRZ\n";
			}
		}
	}
	return 0;
}
