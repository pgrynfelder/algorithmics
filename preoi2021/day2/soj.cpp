#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr ll oo = 1e14 + 7;

struct v {
    vector<ll> t;
    ll rot = 0, mod, modifier = 0;
    v(ll _mod) {
        mod = _mod;
        t.resize(mod);
    }
    void rotate(ll r) {
        rot = (rot + r) % mod;
        if (rot < 0)
            rot += mod;
    }
    ll &operator[](ll i) {
        i %= mod;
        i -= rot;
        while (i < 0)
            i += mod;
        return t[i];
    }
};

int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<ll> good;
    for (int i = 1; i <= n; i++) {
        int a, c;
        cin >> a >> c;
        ll best = 0;
        v t(c);
        for (int r = 1; r < c; r++) {
            t[r] = -oo;
        }
        for (int j = 1; j <= a; j++) {
            ll b;
            cin >> b;
            t.rotate(b);
            if (t[b] == -oo) { // if never reached before, else it's best just to
                            // add cuz b >= 0
                t[b] = -t.modifier;
            }
            t.modifier += b;
            best = max(best, t[0] + t.modifier);

            // cout << "current rests: ";
            // for (int r = 0; r < c; r++){
            //     cout << t[r] + t.modifier << " ";
            // }
            // cout << "\n";

        }
        good.push_back(best);
    }

    // cout << "good: ";
    // for (ull x : good){
    //     cout << x << " ";
    // }
    // cout << "\n";

    set<ull, greater<ull>> gauss;
    for (ull x : good) {
        for (ull y : gauss) {
            x = min(x, x ^ y);
        }
        if (x != 0)
            gauss.insert(x);
    }
    cin >> q;
    while (q--) {
        ull x;
        cin >> x;
        for (ull y : gauss) {
            x = min(x, x ^ y);
        }
        if (x == 0) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}