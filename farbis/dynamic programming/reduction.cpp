#include<bits/stdc++.h>
using namespace std;

const int N = 200007;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a;
    long long result = 0;
    cin >> a;
    result += a;
    cin >> a;
    result -= a;
    for (int i = 0; i < n - 2; i++){
        cin >> a;
        result += a >= 0 ? a : -a;
    }
    cout << result << '\n';
    return 0;
}
