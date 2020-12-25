#include<bits/stdc++.h>

using namespace std;

priority_queue<vector<int>> Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        vector<int> xd = {0,0};
        cin >> xd[0];
        cin >> xd[1];
        Q.push(xd);
    }
    while (!Q.empty()){
        auto xd = Q.top();
        Q.pop();
        cout << xd[0] << ' '<< xd[1] << '\n';
    }
	return 0;
}