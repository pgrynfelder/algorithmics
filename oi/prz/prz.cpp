#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7, M = 1e5 + 7, Z = 1e3 + 7, MOD = 1e9 + 7;
int n, m, z;

int FU[N];
int S[N];

int f(int a){
  if (FU[a] != a){
    FU[a] = f(FU[a]);
  }
  return FU[a];
}
void u(int a, int b){ // subjunct b to a
  if (f(a) == f(b)) return;
  if (S[f(b)] > S[f(a)]){
    swap(a, b);
  }
  S[f(a)] += S[f(b)];
  FU[f(b)] = f(a);
}

int power(int m, unsigned long long n){
    int res = 1;
    while (n > 0) {
        if(n & 1) {
            res = (unsigned long long)res * m % MOD;
        }
        m = (unsigned long long)m * m % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> z;
  for (int i = 1; i <= n; i++){
    FU[i] = i;
    S[i] = 1; 
  }
  for (int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    u(a, b);
  }
  unordered_set<int> unions;
  for (int i = 1; i<=n;i++){
    unions.insert(f(i));
  }
  for (int i = 1; i <= z; i++){
    int x;
    cin >> x;
    unsigned long long result = 0;
    for (int xd : unions){
      if (S[xd] & 1){
        result =  (result + power(x-1, S[xd]) - (x-1) ) % MOD;
      }
      else {
        result = (result + power(x-1, S[xd]) + (x-1)) % MOD;
      }
    }
    cout << result << "\n";
  }
  return 0;
}