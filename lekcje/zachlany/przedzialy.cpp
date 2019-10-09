#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int result = 0;
    cin >> n;
    vector<pair<int, int>> V(n);
    for (int i = 0; i < n; i++){
        cin >> V[i].first >> V[i].second;
    }
    sort(V.begin(), V.end(), [&](const pair<int,int> a, const pair<int, int> b){return a.second < b.second;});
    pair<int, int> last = {-1,-1};
    for (auto current : V){
        if (last.second <= current.first){
            last = current;
            result++;
        }
    }
    cout << result << "\n";   
    
    return 0;
}
