#include<bits/stdc++.h>

using namespace std;

stack<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    int result = 0;
    cin >> q;
    s.push(-1);
    while (q-->0){
        int _a, a;
        cin >> _a >> a;
        while(a < s.top()){
            s.pop();
            result++;
        }
        if (a != s.top()){
            s.push(a);
        }
    }
    result += s.size();
    cout << result - 1 << '\n';
    return 0;
}