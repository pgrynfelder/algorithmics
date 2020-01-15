#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e3 + 7;
constexpr int inf = N * N;
int n;
pair<int,int>seq[2*N];
int pos[2][N];
int dp[N][N]; // dp for a elements from A and b elements from B

template<typename T>
struct Tree {
    int n = 1;
    vector<T> elements;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        elements.resize(n, -inf);
        n >>= 1;
        // cout << n << "\n";
    }
    void insert(int i, T x){
        i += n;
        elements[i] = x;
        while (i > 1){
            i >>= 1;
            elements[i] = elements[2*i] + elements[2*i+1];
        }
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid)
            result += (_read(a, b, l, mid, 2*i));
        if (b >= mid + 1)
            result = (_read(a, b, mid+1, r, 2*i + 1));
        return result;
    }
    T read(int a, int b){
        return _read(a, b, 0, n-1, 1);
    }    
    void print(){
         int i = 1;
         int m = 1;
         int lim = n*2;
         while (i < lim){
            while (i < m){
                cout << elements[i] << ' ';
                i++;
            }
            m *= 2;
            cout << "\n";
         }
    }
};



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<Tree<int>> biggerA(N, Tree<int>(2*N));
	vector<Tree<int>> biggerB(N, Tree<int>(2*N));
	
	for (int i = 1; i <= 2*n; i++){
		char c; int x;
		cin >> c >> x;
		if (c == 'A'){
			seq[i] = {0, x};
			pos[0][x] = i;
			for (int a = x - 1; a >= 0; a--){
				biggerA[a].insert(i, 1);
			}
		}
		else {
			seq[i] = {1, x};
			pos[1][x] = i;
			for (int a = x - 1; a >= 0; a--){
				biggerB[a].insert(i, 1);
			}
		}
	}
	dp[1][0] = pos[0][1]-1;
	dp[0][1] = pos[1][1]-1;
	dp[0][0] = inf;
	
	// dp[a][b] = dp[a-1][b] + abs(a + b - pos[0][a] - countA za >= a - countB za >= b)
	for (int a = 1; a <= n; a++){
		int b = 0;
		dp[a][b] = dp[a-1][b] + abs(a + b - pos[0][a] - biggerA[a-1].read(pos[0][a], n) - biggerB[b].read(pos[0][a], n));
	}
	for (int b = 1; b <= n; b++){
		int a = 0;
		dp[a][b] = dp[a][b-1] + abs(a + b - pos[1][b] - biggerA[a].read(pos[1][b], n) - biggerB[b-1].read(pos[1][b], n));
	}
	for (int a = 1; a <= n; a++){
		for (int b = 1; b <= n; b++){
		dp[a][b] = min(dp[a-1][b] + abs(a + b - pos[0][a] - biggerA[a-1].read(pos[0][a], n) - biggerB[b].read(pos[0][a], n)),
			dp[a][b-1] + abs(a + b - pos[1][b] - biggerA[a].read(pos[1][b], n) - biggerB[b-1].read(pos[1][b], n)));}
	}
	cout << dp[n][n] << "\n";
	return 0;
}
