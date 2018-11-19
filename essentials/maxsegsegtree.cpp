#include<bits/stdc++.h>

using namespace std;

struct T {
	int32_t t[1000007];
	bitset<1000007> star;
	uint32_t s = 1;
	uint32_t d;
	
	T(uint32_t x){
		d = x;
		while (s < d){
			s*=2;
		}
		s /= 2;
	}

	void print(){
		for (uint32_t i = 1; i < s+d; i*= 2){
			for (uint32_t j = i; j < 2*i; j++){
				cout << t[j] << ' ';
			}
			cout << '\n';
		}
	}

	void insert(int32_t v, uint32_t i, uint32_t l, uint32_t r, uint32_t p, uint32_t q){
		if (l > q or r < p){
			return;
		}

		if (l >= p and r <= q){
			t[i] = max(t[i], v);
			//star[i] = true;
		} 
		else {
			insert(v, i*2, l, (l+r)/2, p, q);
			insert(v, i*2+1, (l+r)/2+1, r, p, q);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	uint32_t xd, a, b; int32_t v;
	cin >> xd;
	T t(xd);
	cin >> a >> b >> v;
  	t.insert(v, 1, 1, t.d, a, b);
  	t.print();
	return 0;
}
