#include<bits/stdc++.h>

using namespace std;

int acount[30];
int bcount[30];

int main(){
	int result = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string a, b, newa, newb;

	cin >> a >> b;

	for (char x:a){
		acount[x-97] += 1;
	}
	for (char x:b){
		bcount[x-97] += 1;
	}

	for (int i = 0; i < 26; i++){
		int eszkere = min(acount[i], bcount[i]);
		acount[i] = bcount[i] = eszkere;
		result += eszkere;
	}
	for (char x:a){
		if (acount[x-97] > 0){
			newa += x;
			acount[x-97] -= 1;
		}
	}
	for (char x:b){
		if (bcount[x-97] > 0){
			newb += x;
			bcount[x-97] -= 1;
		}
	}
	if (result > 0) cout << result << "\n" << newa << "\n" << result << "\n" << newb << "\n";
	else cout << "BRAK" << "\n";
	return 0;
}
