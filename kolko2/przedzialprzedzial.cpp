#include<bits/stdc++.h>

using namespace std;

pair<bool, uint32_t>  T[2000007];
uint32_t size=1;

uint32_t check(uint32_t i, uint32_t l, uint32_t r, uint32_t a, uint32_t b){
	
	if (b < l or a > r){
		return 0;
	}
	else if (a <= l and b >= r){
		return T[i].second;
	}
	else {
		if (T[i].first){
			T[i].first = false;
			T[i*2].first = true;
			T[i*2+1].first = true;
			T[i*2].second = T[i].second;
			T[i*2+1].second = T[i].second;
		}
		return max(check(i*2, l, (l+r)/2, a, b), check(i*2+1, (l+r)/2+1, r, a, b));
	}

}

void add(uint32_t x, uint32_t i, uint32_t l, uint32_t r, uint32_t a, uint32_t b){
	//cout << i <<' '<< l <<' '<< r <<' '<< a <<' '<< b << '\n';
	if (b < l or a > r){
	}
	else if (a <= l and b >= r){
		T[i].second = x;
		T[i].first = true;
		//cout << "properly finished adding\n";
	}
	else {	
		//T[i].second = x;
		add(x, i*2, l, (l+r)/2, a, b);
		add(x, i*2+1, (l+r)/2+1, r, a, b);
		T[i].second = max(T[i*2].second, T[i*2+1].second);
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t d, n;
	cin >> d >> n;

	while (size < d*2){
		size *= 2;
	}
	//cout << size << '\n';

	for (uint32_t i = 0; i < n; i++){
		uint32_t a, b, lvl;
		cin >> a >> b;

		lvl = 1 + check(1, 1, size/2, b, a+b-1);
		//cout << lvl << '\n';
		add(lvl, 1, 1, size/2, b, a+b-1);
	}
	//cout << '\n';
	for (uint32_t i = 1; i < size; i *= 2){
		for (uint32_t j = i; j < i*2; j++){
			cout << T[j].second;
			if (T[j].first) cout << '*';
			cout << ' ';
		}
		cout << '\n';
	}
	cout << T[1].second << '\n';
	return 0;
}
