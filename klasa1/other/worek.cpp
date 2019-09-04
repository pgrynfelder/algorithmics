#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t[1000007];

int bs(ll x, int l, int r){
	int mid;
	while (l < r){
		mid = (l+r)/2;
		if (t[mid] >= x){
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> t[i];
	}
	sort(t, t+n);
	t[n] = 1000000000000000001;
	cin >> q;
	for (int i = 0; i < q; i++){
		ll x;
		cin >> x;
		cout << bs(x+1, 0, n) - bs(x, 0, n) << '\n';
	}
	//cout << bs(2+1, 0, n-1) - bs(2, 0, n-1) << '\n';

	return 0;
}
