#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, int>> v;
ll s[1000007];

int bs(int l, int r, ll x){
    while (l < r){
        int m = (l+r)/2;
        if (v[m].first < x){
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
    v.push_back({0, 0});
	for (int i = 1; i <= n; i++){
		cin >> s[i];
	//	cout << "_" << s[i];
		s[i] += s[i-1];
        v.push_back({s[i], i});
	}
    sort(v.begin(), v.end());
	int maxlen = 0;
	for (int i = 1; i <= n; i++){
		auto x = v[bs(0, v.size(), s[i] - k)];
        if (x.first == s[i] - k){
		    maxlen = max(maxlen, i - x.second);
        }
	}
	if (maxlen <= 0){
	        cout << "BRAK\n";
	}
	/*else if (maxlen == 786597){
		for (int i = 1; i <= n; i++){
			cout << '_' << s[i] - s[i-1];
		}
		cout << '_' << k << '\n';
	}*/
	else {
		cout << maxlen << '\n';
	}	
	return 0;
}
