#include<bits/stdc++.h>

using namespace std;

int t[500007];

int lbs(int *v, double x, int l, int r){
	while (l < r){
		int mid = (l+r)/2;
		if (x <= v[mid]){
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	return l;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		t[i] = max(a, t[i-1]);
	}
	t[n+1] = INT_MAX;
	for (int i = 0; i < m; i++){
		int b;
		cin >> b;
		cout << lbs(t, b-0.1, 0, n+1)-1 << ' ';
	}
	return 0;
}