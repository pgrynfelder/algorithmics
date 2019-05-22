#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t[20007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k;
    cin >> n >> k;
    //cout << n << '_' << k;
    for (int i = 0; i < n; i++){
        cin >> t[i];
        //cout << "_" << t[i];
    }
    int i = 0, j = 0, result = 0, credits = k;
    while (i < n and j < n){
        if (t[j+1] - t[j] <= credits){
            credits -= max(0, t[j+1] - t[j]);
            j++;
            if (j >= n){break;}
        }
        else {
            if (t[i+1] > t[i]){
                credits += t[i+1] - t[i];
            }
            i++;
        }
        result = max(j-i+1, result);
    }

    reverse(t, t+n);
    i = 0;
    j = 0;
    credits = k;
    while (i < n and j < n){
        if (t[j+1] - t[j] <= credits){
            credits -= max(0, t[j+1] - t[j]);
            j++;
            if (j >= n){break;}
        }
        else {
            if (t[i+1] > t[i]){
                credits += t[i+1] - t[i];
            }
            i++;
        }
        result = max(j-i+1, result);
    }

    cout << result << '\n';
}