#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 +7;
int ps[N];
string s;

void prefix_suffix(){
    int n = s.size();
    ps[0] = -1;
    ps[1] = 0;
    for (int i = 2; i < n; i++){
        int candidate = ps[i-1];
        while (s[i] != s[candidate + 1] and candidate >= 0) 
            candidate = ps[candidate]
        ps[i] = candidate + 1;
    }
}
