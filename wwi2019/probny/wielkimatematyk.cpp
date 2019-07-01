#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> seq;
	int a;
	while (cin >> a){
		seq.push_back(a);
	}
	const int n = seq.size();	
	vector<bool> can(n+1, false); // can a sequence begin there
	can[n] = true;
	return 0;
}
