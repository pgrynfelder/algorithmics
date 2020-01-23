#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;

int n, t;

int ptr[N], t1[N], t2[N];
int s[N];

void kmp(){
    int candidate = 0;
    t2[0] = t2[1] = 0;
    for (int i = 2; i <= n; i++){
        candidate = t2[i-1];
        while (candidate and s[candidate + 1] != s[i]){
            candidate = t2[candidate];
        }
        if (s[candidate + 1] == s[i]) {
            t2[i] = candidate + 1;
        }
        else {
            t2[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    t++;
    while(t-->1){
        cin >> n;
        bool broke = false;
        int curr = -1, prev = -1;
        for (int i = 1; i <= n; i++){
            cin >> curr;
            t1[i] = curr;
            if (curr - prev > 1 or curr < 0){
                cout << "NIE\n";
                broke = true;
                break;
            }
            ptr[i] = curr;
            prev = curr;
        }
        if (broke) continue;
        ptr[1] = 1;
        s[1] = 'a';
        s[0] = 'b';
        for (int i = 2; i <= n; i++){
            s[i] = s[ptr[i]];
        }
        s[0] = 'c';
        s[n+1] = 'd';
        kmp();
        for (int i = 1; i <= n; i++){
//            cout << t2[i] << " ";
            if (t2[i] != t1[i]){
                cout << "NIE\n";
                broke = true;
                break;
            }
        }
        if (broke) continue;
        cout << "TAK\n";
        for (int i = 1; i <= n; i++){
            cout << (char)s[i];
        }
        cout << "\n";
    }

}
