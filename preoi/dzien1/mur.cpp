#include<iostream>
#include<stack>
using namespace std;

int n;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long result = 0;
	cin >> n;
	stack<int> vals;
	vals.push(0);
	int curr, prev = 0;
	for (int i = 0; i < n; i++){
		cin >> curr;
		if (curr == prev) continue;
		while (vals.top() > curr){
			// cout << i << ": " << vals.top() << "\n";
			vals.pop();
			result++;
		}
		if (curr != vals.top()) vals.push(curr);
		prev = curr;
	}
	while (vals.top() > 0){
		vals.pop();
		result++;
	}
	cout << result << "\n";
	return 0;
}

