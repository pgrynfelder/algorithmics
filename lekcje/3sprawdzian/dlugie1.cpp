#include<bits/stdc++.h>
using namespace std;

constexpr int N = 20, Q = 1e7 + 7, powN = (1<<20)+7;
struct matrix {
	int h, w;
	int a[N];
	
	matrix() {
		h = w = 0;
	}
	
	matrix(int _h, int _w) {
		h = _h, w = _w;
		
		for(int i = 0; i < h; ++i) {
			a[i] = 0;
		}
	}
	matrix operator* (matrix &other) {
		matrix result(h, other.w);		
		for(int j = 0; j < result.w; ++j) {
			int current = 0;
			for(int i = 0; i < other.h; ++i) {
				if(other.a[i] >> j & 1) {
					current |= 1 << i;
				}
			}
			
			for(int i = 0; i < result.h; ++i) {
				if(a[i] & current) {
					result.a[i] |= 1 << j;
				}
			}
		}
		
		return result;
	}
};
int res[Q];
int n, m, q;
unsigned long long S, A, B, L;
unsigned long long ramdom(){
	S = S * A + B;
	return S;
}
matrix pre[powN];
char hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int beg[N];
int cyc[N];
int found[powN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	pre[0] = matrix(n,n);
	for (int i = 0; i < n; i++){
		pre[0].a[i] = 1 << i;
	}
	pre[1] = matrix(n,n);
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		pre[1].a[u] |= 1 << v; // can pass from u to v
	}
	cin >> q >> S >> A >> B >> L;
	for (int i = 0; i < powN; i++){
		found[i] = -1;
	}
    int computed = 1;
	for (int u = 0; u < n; u++){
		for (int i = 0; i < powN; i++){
            while (i > computed){
                computed++;
                pre[computed] = pre[computed-1] * pre[1];
            }
			if (found[pre[i].a[u]] >= 0){
				beg[u] = found[pre[i].a[u]];
				cyc[u] = i - found[pre[i].a[u]];
				for (int j = 0; j <= i; j++){
					found[pre[j].a[u]] = -1;
				}
				break;
			}
			found[pre[i].a[u]] = i; 
		}
	}
	for (int i = 0; i < q; i++){
		unsigned long long u, v, k;
		u = ramdom() % n;
		v = ramdom() % n;
		k = ramdom() % L;
		if (k > beg[u]){
			k = ((k - beg[u]) % cyc[u]) + beg[u];
		}
		
		res[i] = (pre[k].a[u] >> v) & 1;
	}
	reverse(&(res[0]), &(res[q]));
	string answer = "";
	for (int i = 0; i < q; i+= 4){
		int current = 0;
		for (int j = 3; j >= 0; j--){
			current = (current << 1) | res[i + j];
		}
		answer += hexa[current];
	}
	string s = "";
	bool beginning = true;
	for (int i = answer.size() - 1; i >= 0; i--){
		if (answer[i] == '0' and beginning == true) continue;
		s += answer[i];
		beginning = false;
	}
	if (s.size()){
		cout << s;
	}
	else {
		cout << 0;
	}
	/*cout << "\n"; for (int i = 0; i < q; i++) cout << res[i];
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << beg[i] << " " << cyc[i] << "\n";
    */
    return 0;
}

/*
5 5 
0 2
2 4
4 1
1 0
3 2
9 1 5720387 2015 5

23 
(000100011)
*/
