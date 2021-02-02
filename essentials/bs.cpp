#include<bits/stdc++.h>
using namespace std;

constexpr int N = 10000;

int f(int x){
    return 2*x;
}


int bs(int x, int l, int r){
    while (l < r){
        int mid = l + (r-l)/2;
        if (f(mid) >= x){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << f(l) << "\n";
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    cout << bs(x, 1, 1000) << "\n";
    return 0;
}
