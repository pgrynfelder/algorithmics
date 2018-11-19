#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	uint32_t cuts = 0, d;
	stack<uint32_t> S;
	uint32_t a;
	cin >> d;
	S.push(INT_MAX);
	for (uint32_t i = 0; i < d; i++){
		cin >> a;
		if (a > S.top()){
			cuts++; // cuts should be added also when a increments
			while (a > S.top()){
				S.pop();
			}
		}	
		S.push(a);
	}
	uint32_t previous = S.top();
	while (!S.empty()){
		if (S.top() > previous){
			cuts++;
		}
		previous = S.top();
		//cout << previous << ' ';
		S.pop();
	}
	cout << cuts << '\n';
	return 0;

