#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int t[1000007];
ll s[1000007];
vector<pair<int,int>> fields;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k, b, d;
    cin >> n >> k >> b >> d;
    //cout << n << '_' << k;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        s[i] = s[i-1]+t[i];
        //cout << "_" << t[i];
    }
    int i = 1, j = 1, current = 0, result = 0;
    
    if (t[j]%k!=0 and current + 1 > b){
            i++;
        }
    else {
        if (t[j]%k!=0){
            current++;
        }
    }
    if (j - i + 1 > result){
        fields.clear();
        result = j - i + 1;
    }
    if (result == j - i + 1){
        fields.push_back({i,j});
    }
    
    while (i <= n and j <= n){
        if (t[j+1]%k!=0 and current + 1 > b){
            if (t[i]%k!=0){
                current--;
            }
            i++;
        }
        else {
            j++;
            if (j > n){break;}
            if (t[j]%k!=0){
                current++;
            }
        }
        if (j - i + 1 > result){
            fields.clear();
            result = j - i + 1;
        }
        if (result == j - i + 1){
            fields.push_back({i,j});
        }
    }
    if (fields.empty()){
        cout << "NIE\n";
        return 0;
    }
    double bestav = 0; int besti = 0;
    for (int i = 0; i < fields.size(); i++){
        //cout << fields[i].first << ' ' << fields[i].second << '\n';
        double av = (double)(s[fields[i].second] - s[fields[i].first-1])/(double)(fields[i].second-fields[i].first+1);
        //cout << s[fields[i].second] << ' ' << s[fields[i].first-1] << '\n';
        if (av > bestav){
            bestav = av;
            besti = i;
        }
        else if (av == bestav){
            besti = max(besti, i);
        }
    }
    if (fields[besti].second - fields[besti].first + 1 == 0){
        cout << "NIE\n";
        return 0;
    }
    cout << fields[besti].second - fields[besti].first + 1 << '\n';
    cout << fixed << setprecision(d) << bestav << '\n';
    for (int i = fields[besti].first; i <= fields[besti].second; i++){
        cout << t[i] << ' ';
    }
    return 0;
}