#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, result = 0;

	cin >> n;

	for (int i = 0; i < n-1; i++){
		int a;
		cin >> a;
		result += a;
	}
	cout << n*(n+1)/2 - result << "\n";
	return 0;
}
