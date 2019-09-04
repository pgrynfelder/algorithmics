#include<bits/stdc++.h>

using namespace std;

struct Person {
	string name;
	uint32_t age;
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<Person> V;
	V.push_back({"Piotr", 16});
	V.push_back({"Kubin", 15});
	
	uint32_t n = V.size();
	for (uint32_t i = 0; i < n; i++){
		cout << V[i].name << ' ' << V[i].age << '\n';
	}

	return 0;
}
