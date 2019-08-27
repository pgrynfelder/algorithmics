#include<bits/stdc++.h>
using namespace std;

string word;
const int N = 1e6+7;
constexpr uint M = 1e9+7;
constexpr unsigned long long M2 = (unsigned long long)M * M;
uint B[N] = {1, 313};
uint H[2*N];
int a, n;

uint get_hash(const int &l, const int &r){ // inclusive of l and r
    return (M2 + H[r] - (unsigned long long)H[l-1] * B[r - l + 1]) % M; 
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
    for (int i = 2; i < N; i++){
        B[i] = (unsigned long long)B[i-1] * B[1] % M;
    }
    cin >> a;
    
    while (a--){
        cin >> n;
        cin >> word;
        word = word + word;
        // cout << get_hash(1,n) << '\n' << get_hash2(1,n) << '\n';
        for (int i = 1; i < word.size(); i++){
            H[i] = ((unsigned long long)H[i-1] * B[1] + word[i-1]) % M;
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