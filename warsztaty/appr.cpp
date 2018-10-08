#include<bits/stdc++.h>

using namespace std;

vector<int32_t> A;
vector<int32_t> B;

bool re(int32_t w){
	int32_t min = A[0];
	for (int32_t i = 1; i < A.size(); i++){
		min = max(min + 1, A[i] - w);
		if (min > A[i] + w){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int32_t a;
	while(cin >> a){
		A.push_back(a);
		if (cin.peek() == '\n') break;
	}
	
	return 0;
}
