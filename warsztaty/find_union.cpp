#include<bits/stdc++.h>

using namespace std;

struct fu {
	int repr, 
	int rozm;
};

fu FU[1000000];

int Find(int w){
	if (w == FU[w].repr) return w;
	FU[w].repr = Find(FU[w].repr);
	return FU[w].repr;
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(FU[a].rozm > FU[b].rozm){
		FU[b].repr = a;
		FU[a].rozm += FU[b].rozm;
	}
	else {
		FU[a].repr = b;
		FU[b].rozm += FU[a].rozm;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
