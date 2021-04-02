#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, pair<ll,ll>> gcd(ll a, ll b){
    ll newk1, newk2, prevk1 = 1, prevk2 = 0, k1 = 0, k2 = 1, c;
    while (b > 0 and a > 0){
        if (b > a){
            swap(prevk1, k1);
            swap(prevk2, k2);
            swap(a, b);
        }
        ll div = a / b;
        // c = a % b;
        c = a - b * div;
        newk1 = prevk1 - k1 * div;
        newk2 = prevk2 - k2 * div;
        prevk1 = k1;
        prevk2 = k2;
        k1 = newk1;
        k2 = newk2;
        a = b;
        b = c;
    }
    // cout << a << " " << prevk1 << " " << prevk2 << "\n";
    return {a, pair<ll, ll>(prevk1, prevk2)};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b, m;
    cin >> a >> b >> m; 
    ll scale = __gcd(a, __gcd(b, m));
    a /= scale; b /= scale; m /= scale;
    auto xd = gcd(a, m).second; 
    ll x = (xd.first * b % m + m) % m;
    // cout << xd.first << " " << x << "\n";
    if (((a*x - b)% m + m)%m == 0){
        cout << x << "\n";
    }
    else {
        cout << "NIE\n";
    }
    return 0;
}
