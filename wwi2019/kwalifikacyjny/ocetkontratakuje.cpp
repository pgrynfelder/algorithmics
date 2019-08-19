#include<bits/stdc++.h>
using namespace std;

int main(){
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	auto cmp = [&](int a, int b){return a > b;};
	priority_queue<int, vector<int>, decltype(cmp)> q2(cmp); // smallest first
	priority_queue<int> q1; // biggest first
	while (n-->0){
		int a;
		cin >> a;
		if (a == 0){
			cout << q2.top() << '\n';
			q1.push(q2.top());
			q2.pop();
		}
		else if (a == 1){
			int x;
			cin >> x;
			if (!q1.empty() and x < q1.top()){
				q2.push(q1.top());
				q1.pop();
				q1.push(x);
			}
			else {
				q2.push(x);
			}
		}
	}
   	return 0;
}
