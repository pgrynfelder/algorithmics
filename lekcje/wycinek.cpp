#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k, d, x;
    cin >> n >> k >> d >> x;
    cout << n << '_' << k << '_' << d << '_' << x << '_';
    for (int i = 0; i < n; i++){
        cin >> t[i];
        cout << "_" << t[i];
    }
    int i = 0, j = 0;
    /*while (i < n and j < n){
    }*/
}