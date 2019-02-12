#include<bits/stdc++.h>

using namespace std;
		
unordered_map<string, string> FU;

string f(string x){
	if (FU[x] == ""){
		FU[x] = x;
	}
	if (FU[x] == x){
		return x;
	}
	FU[x] = f(FU[x]);
	return FU[x];
}

void u(string x, string y){
	string a = f(x), b = f(y);
	FU[b] = a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while(n-->0){
		string s, a, b;
		cin >> s >> a >> b;
		if (s == "sending"){
			if (f(a) == f(b)){
				cout << "Tak\n";
			}
			else {
				cout << "Nie\n";
			}
		}
		else if (s == "connect"){
			u(a, b);
		}
	}
}




