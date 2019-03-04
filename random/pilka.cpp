#include <bits/stdc++.h>

using namespace std;

const double m = 2;
const double h = 1.2;
const double vi = 10;
const double g = 10;
int main(){
  double t;
  double vg;
  cin >> t;
  vg = sqrt(2*g*h);
  cout << setprecision(3) << fixed << 2 * vg * m / t << endl;

  return 0;
}

