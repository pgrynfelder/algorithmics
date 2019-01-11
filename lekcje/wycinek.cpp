#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int,int> m;
int s[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	m[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
	//	cout << "_" << s[i];
		s[i] += s[i-1];
		if (m.count(s[i]) == 0){
			m[s[i]] = i;
		}
		else {
			m[s[i]] = min(m[s[i]], i);
		}
	}
	int maxlen = 0;
	for (int i = 1; i <= n; i++){
		if (m.count(s[i]-k)==1){
			maxlen = max(maxlen, i - m[s[i]-k]);
		}
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
