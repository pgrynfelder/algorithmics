#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> xd(8);
    int n;
    cin >> n;
    while (n-->0){
        int lol;
        cin >> lol;
        if (lol){
            int a, b, c;
            cin >> a >> b >> c;
            for (int i = a-1; i<=b-1; i++){
                xd[i] += c;
            }
        }
        else {
            int a, b;
            cin >> a >> b;
            int mx = INT_MIN;
            for (int i = a-1; i<=b-1; i++){
                mx = max(mx, xd[i]);
            }
            cout << mx << '\n';
        }
    }
    return 0;
}
