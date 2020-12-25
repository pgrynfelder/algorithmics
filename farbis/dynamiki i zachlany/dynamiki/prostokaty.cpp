#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int prev1 = 0, prev2 = 0; // 1 height 2 width
    int current1, current2;
    long long result1 = 0, result2 = 0; // 1 wasnt rotated, 2 was rotated
    long long new1 = 0, new2 = 0;
    while (n--){
        cin >> current1 >> current2;
        new1 = max(abs((long long)current1 - prev1) + current2 + result1, abs((long long)current1-prev2) + current2 + result2);
        new2 = max(abs((long long)current2 - prev1) + current1 + result1, abs((long long)current2-prev2) + current1 + result2);
        result1 = new1;
        result2 = new2;
        prev1 = current1;
        prev2 = current2;
    }
    cout << max(result1 + current1, result2 + current2) << '\n';
    return 0;
}

