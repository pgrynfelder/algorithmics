#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[5007];
int b[5007];
int s1[5007];
int s2[5007];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i <= n; i++){
        cin >> s1[i];
    }
    for (int i=1; i <= n; i++){
        cin >> s2[i];
    }

    for (int j = 1; j <= n; j++){
        for (int i = 1; i <= n; i++){
            if (s1[i] == s2[j]){
                b[i] = max(a[i-1] + s1[i], max(b[i-1], a[i]));
            }
            else {
                b[i] = max(b[i-1], a[i]);
            }
        }
        swap(a, b);
    }
    cout << a[n] << "\n";
    return 0;
}