#include<bits/stdc++.h>

using namespace std;

uint32_t XD[5007][5007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string a, b;
	cin >> a >> b;
	uint32_t n = a.size(), m = b.size();

	// XD[i][j] = max(XD[i-1][j], XD[j][i-1], XD[i-1][i-1] + 1 if a[i]==b[i] else 0)
	for (uint32_t i = 0; i < n; i++){
		for (uint32_t j = 0; j < m; j++){
			if (a[i] == b[j]){
				XD[i+1][j+1] = max(max(XD[i][j+1], XD[i+1][j]), XD[i][j] + 1);
			} else {
				XD[i+1][j+1] = max(XD[i][j+1], XD[i+1][j]);
			}
		}
	}
	cout << XD[n][m] << '\n';
	string result = "";
	while (n != 0 and m != 0){
		if (XD[n][m] == XD[n-1][m-1] + 1){
			n--; m--;
			result += a[n];
		}
		else if (XD[n][m] == XD[n-1][m]){
			n--;
		}
		else {
			m--;
		}
	}
	reverse(result.begin(), result.end());
        cout << result << '\n';
	return 0;
}
