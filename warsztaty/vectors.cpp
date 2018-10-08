#include <bits/stdc++.h>

using namespace std;

int t[1000];
vector<int> v;
queue<int> q;
priority_queue<int> pq;


int main(){
	// vector
	v.push_back(3);  // O(1)
	v.size(); // achtung v.size() returns unsigned int, (int) v.size() to fix
	v[0]; // (1)

	// queue
	q.push(5); // O(1) append to end
	q.front(); // O(1) get from front
	q.pop(); // O(1) remove front
	q.size(); // as in vector

	// priority_queue (stores in sorted order)
	pq.push(4); pq.push(43); // O(log n)
	pq.top(); // O(log n) get biggest
	pq.pop(); // O(log n) remove biggest
	
	return 0;
}
