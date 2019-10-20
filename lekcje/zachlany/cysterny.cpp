#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;
int V;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> V;
    vector<pair<int, int>> C(n); // v, c
    
    for (int i = 0; i < n; i++){
        cin >> C[i].first;
    }
    for (int i = 0; i < n; i++){
        cin >> C[i].second;
    }
    sort(C.begin(), C.end(), [&](const pair<int, int> a, const pair<int, int> b){
            return (long long)a.first * b.second < (long long)a.second * b.first;
    });
    // cout << C[0].first << " " <<  C[0].second << "\n";
    double result;
    for (int i = 0; i < n and V > 0; i++){
        if (V >= C[i].first){
            result += C[i].second;
            V -= C[i].first;
        }
        else {
            result += C[i].second * (double) V / C[i].first;
            break;
        }
    }

    cout << fixed << setprecision(8) << result << "\n";
    return 0;
}
