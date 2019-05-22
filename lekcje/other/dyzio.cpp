#include<bits/stdc++.h>

using namespace std;

bool n[(int)10e6+7];
int s[(int)10e6+7];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// sito
	n[0] = true;
	n[1] = true;
	int i = 2;
	while (i <= 1000000){
		if (n[i] == false){
			int k = 2*i;
			while (k <= 1000000){
				n[k] = true;
				k += i;
			}
		}
		i++;
	}
	//
	
	for (int i = 1; i <= 1000000; i++){
		s[i] = s[i-1];
		if (n[i] == false){
			s[i]++;
		}
	}
	int q;
	cin >> q;
	while(q-->0){
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a-1] << '\n';
	}	
	return 0;
}
