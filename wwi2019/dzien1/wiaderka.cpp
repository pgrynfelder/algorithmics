#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct bucket {
    ll x = 0, y = 0, z = 0;
    bucket(ll _x, ll _y, ll _z){
        x = _x;
        y = _y;
        z = _z;
    }
};
int n, k;
vector<bucket> buckets;
bool solve(ll m){
    int q = k+1;
    queue<bucket> poured;
    for (bucket b : buckets){
        if (b.z > m){
            poured.push(b);
        }
    }
    if (poured.size() > k) return false;
    while (q-->1){
        if (poured.empty()) return true;
        bucket b = poured.front();
        poured.pop();
        int r = k - m/b.x;
        if (q >= r){ // gituwa

        }
        else {
            return false;
        }
    }
    return poured.empty();
}

ll bs(ll l, ll r){
    while (l < r){
        ll mid = (l+r)/2;
        if (solve(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    while (n-->0){
        ll x, y, z;
        cin >> x >> y;
        z = k * x + y;
        buckets.push_back({x,y,z});

    }

    sort(buckets.begin(), buckets.end(), [](const bucket &a, const bucket &b) -> bool {return a.x > b.x;});
    cout << bs(0,1e12+7) << '\n';
    return 0;
}
/*

5 4
1 2
10 7
4 2
11 9
12 2
*/