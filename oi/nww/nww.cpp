#include<bits/stdc++.h>
using namespace std;

constexpr int MAXI[] = {0, 0, 0, 1259920, 49488, 7512, 2215, 930, 504, 280, 216, 140, 110, 88, 65, 54, 51, 40, 39, 34, 33, 25, 24, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
constexpr int MAXK = 42;
unordered_map<unsigned long long, pair<int, int>> LCM;
constexpr unsigned long long MAXLCM = 1e18;
constexpr int inf = 1e9;

void preprocess(){
    for (int k = 3; k <= MAXK; k++){
        for (int i = 1; i <= MAXI[k]; i++){
            unsigned long long lcm = 1;
            for (int j = i; j < i + k; j++){
                lcm = lcm / __gcd(lcm, (unsigned long long)j) * j;
                if (lcm > MAXLCM){
                    break;
                }
            }
            pair<int, int> candidate = {i, i + k - 1};
            if ((lcm <= MAXLCM) and (not LCM.count(lcm) or LCM[lcm] > candidate)){
                LCM[lcm] = candidate;
            }
        }
    }
}

void solve(unsigned long long m){
    unsigned long long root = (unsigned long long)sqrt((double)m);
    pair<int, int> candidate = {inf, inf};
    bool found = false;
    if (root * (root + 1) == m) {
        candidate = {root, root+1};
        found = true;
    }
    if (LCM.count(m)){
        candidate = min(candidate, LCM[m]);
        found = true;
    }
    if (found){
        cout << candidate.first << " " << candidate.second << "\n";
    } else {
        cout << "NIE\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preprocess();
    int q; unsigned long long m;
    cin >> q;
    while (q--){
        cin >> m;
        solve(m);
    }
    return 0;
}
