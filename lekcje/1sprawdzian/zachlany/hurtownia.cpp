#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5e4 + 7;
int n;

int del[N];
int ord[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long current = 0;
    int result = 0;
    vector<int> deliveries;
    vector<int> orders;
    priority_queue<int> Q;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> del[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> ord[i];
    }
    for (int i = 1; i <= n; i++){
        current += del[i];
        if (current >= ord[i]){
            current -= ord[i];
            Q.push(ord[i]);
            result++;
        } else {
            if (!Q.empty() and ord[i] < Q.top() and current + Q.top() >= ord[i]){
                current += Q.top();
                current -= ord[i];
                Q.pop();
                Q.push(ord[i]);
            }
        }
    }
    cout << result << "\n";
    return 0;
}

