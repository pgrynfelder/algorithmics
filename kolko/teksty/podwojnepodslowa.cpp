#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int base = 997, m = 1e9+7;



ll t[1000007];
ll b[1000007];

ll h(char s){
    return s;
}

ll hdiff(int n, ll x, ll y){
    return (m + x - (y*b[n]) % m) % m;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;

    t[0] = h(s[0]);
    b[0] = 1;
    for (int i = 1; i < s.size(); i++){
        b[i] = (b[i-1] * base) % m;
        t[i] = ((t[i-1] * base) % m + h(s[i])) % m;
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (hdiff((y-x+1)/2, t[y], t[(x+y-1)/2]) == hdiff((y-x+1)/2, t[(x+y-1)/2], t[x-1])){
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n";
        }
    }
	return 0;
}