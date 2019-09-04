#include<bits/stdc++.h>

using namespace std;

vector<int32_t> mergesort(vector<int32_t> t){
	uint32_t n = t.size();
	if (n < 2) return t;
	n /= 2;
	vector<int32_t> t1, t2;
	for (uint32_t i = 0; i < n/2; i++){
		t1.push_back(t[i]);
	}
	for (uint32_t i = n/2; i < n; i++){
		t2.push_back(t[i]);
	}

	vector<int32_t> t3;
	t1 = mergesort(t1);
	t2 = mergesort(t2);
	
	
	uint32_t i = 0, j = 0, n1 = t1.size(), n2 = t2.size();

	while (i < n1 and j < n2){
		if (t1[i] < t2[j]){
			t3.push_back(t1[i]);
			i++;
		}
		else {
			t3.push_back(t2[j]);
			j++;
		}
	}
	while (i < n1){
		t3.push_back(t1[i]);
		i++;
	}
	while (j < n2){
		t3.push_back(t2[j]);
		j++;
	}
	return t;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
