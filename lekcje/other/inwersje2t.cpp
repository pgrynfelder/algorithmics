#include<bits/stdc++.h>

using namespace std;

int32_t t[100000]; // haupttabelle
int32_t h[100000]; // hilfstabelle
int32_t inv;

void ms(int32_t l, int32_t r){
	//cout << "performed ms " << l << ' ' << r << '\n';
	if (l >= r){
		return;
	}
	//cout << "performed ms " << l << ' ' << r << '\n';
	ms(l, (l+r)/2);
	ms((l+r)/2+1, r);
	
	for (int32_t i = l; i <= r; i++){
		h[i] = t[i];
	}

	int32_t i = l, a = l, b = (l+r)/2+1;
	while (a <= (l+r)/2 and b <= r){
		if (h[a] <= h[b]){
			t[i] = h[a];
			a++;
		} else {
			t[i] = h[b];
			b++;
			inv += (l+r)/2 - a + 1;
		}
		i++;
	}
	while (a <= (l+r)/2){
		t[i] = h[a];
		a++;
		i++;
	}
	while (b <= r){
		t[i] = h[b];
		b++;
		i++;
	}
	// HAAAARY
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	uint32_t d;
	cin >> d;
	for (int32_t i = 1; i <= d; i++){
		cin >> t[i];
	}
	ms(1, d);
	/*for (int32_t i = 1; i <= d; i++){
		cout << t[i] << ' ';
	}
	cout << '\n';*/
	cout << inv << '\n';
	return 0;
}
