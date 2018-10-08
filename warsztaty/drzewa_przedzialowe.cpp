#include<bits/stdc++.h>

using namespace std;

int INF = 1e9;
int drzewo[100000];
int maxZPrzedzialu(int a, int b, int l, int p, int i){
	if ( a > p or b < l){
		return -INF;
	}
	else if (a <= l and b >= p){
		return drzewo[i];
	}
	else {
		return max(maxZPrzedzialu(a, b, l, (l+p)/2, i*2),
			   maxZPrzedzialu(a, b, (l+p)/2+1, p, i*2+1));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
