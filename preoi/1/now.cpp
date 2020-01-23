#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

unordered_map<int, int> maxi = {
    {5, 3981},
    {7, 372}, 
    {11, 43}, 
    {13, 24}, 
    {17, 11}, 
    {19, 8}, 
    {23, 6}, 
    {29, 4}, 
    {31, 3}, 
    {37, 3}, 
    {41, 2}, 
    {43, 2}, 
    {47, 2}, 
    {53, 2}, 
    {59, 2}
};
unordered_set<ull> allowed;

ull fastpow(ull x, int p){
    ull res;
    if (p == 1){
        res = x;
    }
    else if (p & 1){
        res = x * fastpow(x, p-1);
    }
    else {
        res = fastpow(x, p / 2);
        res *= res;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int q;
    int result = 0;

    for (pair<int, int> xd : maxi){
        int p = xd.first;
        int i = 2;
        while (i <= xd.second){
            allowed.insert(fastpow(i, p));
            i++;
        }
    }
    cin >> q;
    while (q--){
        ull x;
        cin >> x;
        if (x == 1){
            result++;
            // cout << x << " 1\n";
        }
        else if (fastpow((ull)sqrt((double)x), 2) == x){
            result++;
            // cout << x << " 2\n";
        }
        else if (fastpow((ull)cbrt((double)x), 3) == x){
            result++;
            // cout << x << " 3\n";
        }
        else if (allowed.count(x)){
            result++;
            // cout << x << " 4\n";
        }
    }
    cout << result << "\n";
    return 0;
}