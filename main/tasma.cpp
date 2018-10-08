#include<bits/stdc++.h>

using namespace std;


long long S[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		S[i+1] = S[i] + a;
	}

	long long result = abs(S[1] - (S[n] - S[1]));
	for (int i = 2; i < n; i++){
		result = min(abs(S[i] - (S[n] - S[i])), result);
	}
	cout << result << "\n";
	return 0;
}
