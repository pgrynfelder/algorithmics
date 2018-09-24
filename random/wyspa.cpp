#include <bits/stdc++.h>

using namespace std;

int main() {
  uint64_t max_x, max_y, p, a, b, remaining, h;
  cin >> max_x >> max_y >> p;
  h = max_y + 1;
  while (true) {
    a = p / h;
    remaining = p - a * h;
    b = remaining * 2 / h + a;
    if (a != 0 && a < max_x && b < max_x) break;
    h--;
  }
  cout << "0 0 "<< b <<" 0 "<< a <<" "<< h <<" 0 "<< h;
  return 0;
}
