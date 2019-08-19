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
	vector<bool> can(n+1e6+7, false); // can a sequence begin there
	stack<int> result;
	can[n] = true;
	result.push(n);
	for (int i = n - 1; i > 0; i--){
		if (can[i + seq[i] + 1]){
			can[i] = true;
			result.push(i);
		}
	}
	while (!result.empty()){
		cout << result.top() << ' ';
		result.pop();
	}
	return 0;
}
