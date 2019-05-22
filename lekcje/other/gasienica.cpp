#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t[1000007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    int i = 0, j = 0, roses = 0, cabbage = 0, result = n;
    if (t[i] == 0) { cabbage++;} else {roses++;}
    while (i < n and j < n){
        if (roses < k and j + 1 < n){
            j++;
            if (t[j] == 0){
                cabbage++;
            }
            else {
                roses++;
            }
        }
        else {
            if (roses >= k){ result = min(cabbage, result); };
            if (t[i] == 0){
                cabbage--;
            }
            else {
                roses--;
            }
            i++;
        }
    }
    if (result == n){
        cout << "NIE\n";
    }
    else {
        cout << result << '\n';
    }
}