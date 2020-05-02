#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7, oo = 1e9 + 7;
constexpr bool DEBUG = 1;

int ps[2*N], t[2*N];
int n, m;

bool valid(int smaller, int bigger, int i, int j){
    if (DEBUG) cout << "validation: " << smaller << " " <<  bigger << " " << i << " " << j << "\n";
    return (bigger==oo or t[i] < t[i-j+bigger-1]) and (smaller== -oo or t[i] > t[i-j+smaller-1]);
}

void print(map<int,int> &xd){
    for (auto &lulz : xd){
        cout << lulz.first << " => " << lulz.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        t[a] = i;
    }
    t[n+1] = oo - 1;
    for (int i = n + 2; i < n + 2 + m; i++){
        cin >> t[i];
    }
    map<int, int> prefix;
    ps[0] = 0;
    ps[1] = 0;
    prefix[-oo] = -oo;
    prefix[oo] = oo;
	for (int i = 2; i <= n + m + 1; i++){
        int j = ps[i-1]; // current match length
        auto ub = prefix.upper_bound(t[j+1]);
        int bigger = ub -> second;
        int smaller = (--ub) -> second; // there ain't no equal elems so doesn't matter
        if (DEBUG){
            cout << i << " " << j << ":\n";
            print(prefix);
        }
        while (j > 0 and not valid(smaller, bigger, i, j)){
            int prev = ps[j];
            while (j > prev){
                prefix.erase(t[j]);
                j--;
            }
            ub = prefix.upper_bound(t[j+1]);
            bigger = ub -> second;
            smaller = (--ub) -> second;

            if (DEBUG){
                cout << j << ":\n";
                print(prefix);
            }
        }
        if (valid(smaller, bigger, i, j)){
            prefix[t[j+1]] = j+1;
            j++;

            if (DEBUG){
                cout << "SUCC\n";
                cout << j << ":\n";
                print(prefix);
            }
        }
        ps[i] = j;

    } 
    

    if (DEBUG){
        for (int i = 1; i <= n+m+1; i++){
            cout << t[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n+m+1; i++){
            cout << ps[i] << " ";
        }
    }

    vector<int> output;

    for (int i = n + 2; i <= n+m+1; i++){
        if (ps[i] == n){
            output.push_back(i - 2*n);
        }
    }
    cout << output.size() << "\n";
    for (auto c : output){
        cout << c << " ";
    }
    return 0;
}

/*

5 10
2 1 5 3 4
5 6 3 8 12 7 1 10 11 9

*/