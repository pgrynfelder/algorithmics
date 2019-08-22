#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> difficulty;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> questions;
    difficulty.resize(n+1);
    for (int i = 1; i<=n; i++){
        cin >> difficulty[i];
        questions.push_back(i);
    }
    sort(questions.begin(), questions.end(), [&](const int a, const int b){return difficulty[a] < difficulty[b];});
    
    
    return 0;
}
