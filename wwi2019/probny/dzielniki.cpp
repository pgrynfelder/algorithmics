#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	vector<ll> divs1;
	vector<ll> divs2;
	cin >> n;
	
	ll i = 1;
	while (i*i < n){
		if (n % i == 0){
			divs1.push_back(i);
			divs2.push_back(n / i);
		}
		i++;
	}
	if (i*i == n){
		divs1.push_back(i);
	}
	
	for (int j = 0; j < divs1.size(); j++){
		cout << divs1[j] << '\n';
	}
	for (int j = divs2.size() - 1; j >= 0; j--){
		cout << divs2[j] << '\n';
	}

	return 0;
}
