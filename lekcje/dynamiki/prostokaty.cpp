#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Rect {
    int x = 0, y = 0;
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    vector<Rect> rects(n+2);
    vector<vector<ll>> T(2, vector<ll>(n+2, 0)); // 0 - default oriented, 1 - 90 deg rotated
    for (int i = 1; i <= n; i++){
        cin >> rects[i].y;
        cin >> rects[i].x;
    }
    
    for (int i = 1; i <= n+1; i++){
        T[0][i] = max(T[0][i-1] + abs(rects[i-1].y - rects[i].y), T[1][i-1] + abs(rects[i-1].x - rects[i].y)) + rects[i].x;
        T[1][i] = max(T[0][i-1] + abs(rects[i-1].y - rects[i].x), T[1][i-1] + abs(rects[i-1].x - rects[i].x)) + rects[i].y;
    }
    cout << max(T[0][n+1], T[1][n+1]) << endl;
	return 0;
}