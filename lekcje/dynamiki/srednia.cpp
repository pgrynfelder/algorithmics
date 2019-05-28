#include<bits/stdc++.h>

using namespace std;
const double inf = 1e9;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int len;
	cin >> len;
	vector<vector<double>> A(len, vector<double>(len, -inf));
	for (int i = 0; i < len; i++){
		cin >> A[i][i];
	}
	for (int n = 1; n < len; n++){
		//cout << "n: " << n << endl;
		for (int a = 0; a + n < len; a++){
			//cout << "a: " << a << endl;
			for (int k = a; k < a + n; k++){
				//cout << "k: " << k << endl;
				A[a][a+n] = max(A[a][a+n], 0.5*(A[a][k] + A[k+1][a+n]));
			}
		}
	}
	cout << fixed << setprecision(7) << A[0][len-1] << endl;	
	return 0;
}
