#include<bits/stdc++.h>

using namespace std;

int t[30007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    sort(t, t+n);
    int i = 0, j = i + 2, result = 0;
    while (j < n){
        if (j-i < 3){
            j++;
        }
        else if (t[i] + t[i+1] > t[j]){
            result = max(result, j-i+1);
            j++;
        }
        else {
            i++;
        }
    }
    cout << result << '\n';
}