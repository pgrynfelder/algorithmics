#include<bits/stdc++.h>
using namespace std;

string word;
constexpr int N = 1e6+7;
//constexpr uint M = 1e9+7;
uint B[N] = {1, 313};
uint H[2*N];
int a, n;

constexpr uint K = 31; constexpr uint P = ((uint)1 << K) - 1;
uint mod(unsigned long long x)
{
    x = (x >> K) + (x & P);
    x = (x >> K) + (x & P);
    return x == P ? 0 : x;
}

uint get_hash(const int &l, const int &r){ // inclusive of l and r
    return mod(P + H[r] - mod((unsigned long long)H[l-1] * B[r - l + 1]));
}

bool compare(const int &i1, const int &i2){
    int l = 0, r = n-1;
    while (l < r){
        int mid = (l+r)/2;
        if (get_hash(i1, i1 + mid) == get_hash(i2, i2 + mid)){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return word[i1 + l - 1] < word[i2 + l - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i < N; i++){;
    }
    cin >> a;
    
    while (a--){
        cin >> n;
        cin >> word;
        word = word + word;
        for (int i = 1; i < word.size(); i++){
            H[i] = mod((unsigned long long)H[i-1] * B[1] + word[i-1]);
        }
        int maxi = 1;
        for (int i = 2; i < n; i++){
            if (compare(maxi, i)){
                maxi = i;
            }
        }
        for (int i = maxi; i < maxi + n; i++){
            cout << word[i-1];
        }
        cout << '\n';
    }
    return 0;
}
