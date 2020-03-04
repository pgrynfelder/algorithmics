#include<bits/stdc++.h>
using namespace std;

long long result[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--){
        long long a, b, c;
        cin >> a >> b >> c;
        a += max(result[1], result[2]);
        b += max(result[0], result[2]);
        c += max(result[0], result[1]);
        result[0] = a;
        result[1] = b;
        result[2] = c;
    }
    cout << max(result[0], max(result[1], result[2])) << '\n';
    return 0;
}

