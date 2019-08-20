#include<bits/stdc++.h>

using namespace std;

const double e = 1e-12;
double a0, a1, a2, a3, a4, a5;

double w(double x){
    return a0 + x*(a1 + x*(a2 + x*(a3 + x*(a4 + x*a5))));
}

double bs(double l, double r){
    while (abs(l-r) > e and l < r){
        double mid = (l+r)/2;
        if (w(mid) < 0){
            l = mid;
        }
        else {
            r = mid;
        }
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a5 >> a4 >> a3 >> a2 >> a1 >> a0;
    if (a5 < 0){
        a5 *= -1; a4 *= -1; a3 *= -1; a2 *= -1; a1 *= -1; a0 *= -1;
    }
    cout << fixed << setprecision(6) << bs(-1000, 1000) << '\n';
    return 0;
}
