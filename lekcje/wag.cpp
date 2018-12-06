#include<bits/stdc++.h>

using namespace std;

bool compare(const pair<int32_t, int32_t> &a, const pair<int32_t, int32_t> &b){
	double real_a = a.first;
	for (int32_t i = 0; i < a.second; i++){
		real_a /= 2;
	}
	double real_b = b.first;
	for (int32_t i = 0; i < b.second; i++){
		real_b /= 2;
	}
	if (real_a == real_b){
		return a.first < b.first;
	}
	else {
		return real_a < real_b;
	}
	
}

pair<double, int32_t> t[20007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

       	int32_t n;
        cin >> n;
        for (int32_t i = 0; i < n; i++){
                cin >> t[i].first >> t[i].second;
        }
        sort(t, t+n, compare);
        for (int32_t i = 0; i < n; i++){
                cout << t[i].first << ' ' << t[i].second << '\n';
        }

	return 0;
}
