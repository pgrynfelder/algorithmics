#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// extended euclidean algorithm
pair<ll, pair<ll,ll>> ee(ll a, ll b){
    ll newk1, newk2, prevk1 = 1, prevk2 = 0, k1 = 0, k2 = 1, c;
    while (b > 0 and a > 0){
        if (b > a){
            swap(prevk1, k1);
            swap(prevk2, k2);
            swap(a, b);
        }
        ll div = a / b;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll m1, m2, a1, a2;
    cin >> m1 >> m2 >> a1 >> a2;
    ull M = m1 * m2;
    auto xd = ee(m1, m2).second;
    ll A = (xd.first % m2 + m2) % m2, B = (xd.second % m1 + m1) % m1;

    cout << (((ull)(B * a1 % m1 + m1) % m1 * m2) % M + (ull)(A * a2 % m2 + m2) % m2 * m1) % M << "\n";
    return 0;
}
