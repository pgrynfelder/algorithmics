// set
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    set<int> t;

    while(q--){
        int a;
        cin >> a;
        t.insert(a);
        cout << t.size() << "\n";
    }

    return 0;
}