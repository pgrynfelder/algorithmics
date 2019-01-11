#include<bits/stdc++.h>

using namespace std;
int t[1000007];
long long s[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		s[i] = s[i-1] + t[i];
	}

	return 0;
}
