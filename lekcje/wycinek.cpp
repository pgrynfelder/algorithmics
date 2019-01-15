#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll,int> m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	m.reserve(n);
	m[0] = 0;

	int maxlen = 0;
	ll previous = 0, current = 0;
	for (int i = 1; i <= n; i++){
		cin >> current;
	//	cout << "_" << s[i];
		current += previous;
		if (m.count(current) == 0){
			m[current] = i;
		}
		else {
			m[current] = min(m[current], i);
		}
		
		if (m.count(current-k)==1){
			maxlen = max(maxlen, i - m[current-k]);
		}
		previous = current;
	}
	//for(unordered_map<ll,int>::iterator ii=m.begin();ii!=m.end(); ii++) cout<<(ii->first)<<' '<<(ii->second)<<'\n';
	if (maxlen <= 0){
	        cout << "BRAK\n";
	}
	else {
		cout << maxlen << '\n';
	}	
	return 0;
}
