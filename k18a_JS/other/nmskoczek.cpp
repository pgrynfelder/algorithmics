#include<bits/stdc++.h>

using namespace std;
int32_t gcd(int32_t a, int32_t b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int32_t t, a, b, x1, y1, x2, y2, k;
    cin >> t;
    for (int32_t i; i < t; i++){
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;
        x1 -= x2; y1 -= y2;

        k = gcd(a, b);

        a /= k;
        b /= k;

        if (a % 2 == 1 and b % 2 == 1){
            // mesh 45
            if (x1 % k == 0 and y1 % k == 0) {
                if ( (x1/k + y1/k) % 2 == 0) {
                    cout << "TAK\n";
                    continue;
                }
            }
        }
        else {
            // mesh 0 all
            if (x1 % k == 0 and y1 % k == 0) {
                cout << "TAK\n";
                continue;
            }
        }
        cout << "NIE\n";
        continue;
    }
}