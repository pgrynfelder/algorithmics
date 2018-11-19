#include<bits/stdc++.h>
using namespace std;

// directed cycleless graph

/* METHOD 1
 * choose one vertex
 * go deepest possible dfs post-order (adding to list when perma leavin' vertex)
 */

/* METHOD 2
 * list incoming degrees of vertices
 * those with 0 add to queue
 * for each
 * 	for each child
 * 		if child's incoming degree == 0
 * 			push child to queue
 */

vector<uint32_t> topo(queue<uint32_t> &q){
	for (uint32_t v : vertices){
		if (deg[v]==0){
			q.push(v);
	for (uint32_t v : vertices){
		for (uint32_t w : G[v]){
			if (deg[w]==0){
				q.push();
			}
		}
	}
	

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
