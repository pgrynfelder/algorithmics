#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    ll all = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        t[i] = a;
        all += a;
    }
    int i = 0, j = 0;
    ll mindiff = all, current = t[0];
    while (i < n and j < n){
        if (i >= j and j + 1 < n){
            j++;
            current += t[j];
        }
        else if (all > (current<<1) and j + 1 < n){
            j++;
            current += t[j];
        }
        else {
            current -= t[i];
            i++;
        }
        //cout << i << ' ' << j << '\n';
        mindiff = min(mindiff, abs(all-(current<<1)));
        //cout << current << '\n';
    }
    cout << (all-mindiff)/2 << '\n';
}