#include<bits/stdc++.h>

using namespace std;

//int k[300007];
int xd[300007];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> xd[0];
	for (int i = 1; i < n; i++){
		int x;
		cin >> x;
		xd[i] = min(xd[i-1], x);
	}
	/*for (int i = 0; i < n; i++){
		cout << xd[i] << ' ';
	}*/
	int j = n-1;
	int last;
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		while (true){
			if (j < 0){
				break;
			}
			if (x <= xd[j]){
				last = j;
				j--;
				break;
			}
			j--;
		}
		if (j < 0) {
			break;
		}
	}

	cout << last+1 << '\n';
	return 0;
}

