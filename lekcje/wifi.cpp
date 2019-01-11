#include<bits/stdc++.h>

using namespace std;

bool f(int x, int m, vector<int> &distances){
	int pos = distances[0]+x;
	m--;
	int j = 1;
	while (m-- > 0){
		while (abs(pos - distances[j]) <= x){
			j++;
			if (j >= distances.size()) return true;
		}
		
		pos = distances[j] + x;
	}
	return abs(pos-distances.back()) <= x;
}

int bs(int l, int r, int m, vector<int> &distances){
	while (l < r){
		int mid = (l+r)/2;
		if (f(mid, m, distances) == true){
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int k, n, m;
	cin >> k;
	while (k-- > 0){
		vector<int> distances;
		cin >> n >> m;
		while (m-- > 0){
			int a;
			cin >> a;
			distances.push_back(a*2);
		}
		sort(distances.begin(), distances.end());
		double result = bs(0, distances.back(), n, distances);
		result /= 2;
		cout << fixed << setprecision(1) << result << '\n';
	}
	return 0;
}
