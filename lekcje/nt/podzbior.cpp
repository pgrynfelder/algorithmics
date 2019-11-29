// podzbior, subset, subset of given xor
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

constexpr int m = 64;
int n, q;
vector<vector<int>> es_base;
vector<int> sol;
vector<ull> numbers;

int gauss(ull _d){
    ull d = _d;
    vector<vector<int>> es = es_base;
    vector<int> expected = vector<int>(m);
    for (int j = 0; j < m; j++){
        expected[j] = es[j][n] = d & 1;
        d >>= 1;
    }

    // for (int x = 0; x < m; x++){
    //     for (int i = 0; i < n + 1; i++){
    //         cout << es[x][i] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int x = 0; x < n; x++){
        bool found = false;
        // for (int i = 0; i <= x; i++)
        if (es[x][x]){
            found = true;
        }
        for (int i = x+1; i < m; i++){
            if (es[i][x] > es[x][x]){
                swap(es[i], es[x]);
                found = true;
            }
        }
        if (found){
            for (int y = 0; y < m; y++){
                if (y != x and es[y][x] == 1){
                    for (int j = x+1; j < n + 1; j++){
                        es[y][j] ^= es[x][j];
                    }
                    es[y][x] = 0;
                }
            }
        }
        else {
            // cout << x << " NOT FOUND\n";
            for (int y = 0; y < m; y++){
                es[y][x] = 0;
            }
        }
    }
    for (int x = 0; x < m; x++){
        for (int i = 0; i < n + 1; i++){
            cout << es[x][i] << " ";
        }
        cout << "\n";
    }

    for (int x = m-1; x >= 0; x--){
        int i = 0;
        while (i < n){
            if (es[x][i] != 0){
                break;
            }
            i++;
        }
        // cout << i << "\n"; 
        if (i == n and es[x][i] != 0){
            return 0;
        }
        else if (i == n and es[x][i] == 0){
            continue;
        }
        else {
            sol[i] = es[x][n];
            for (int j = i + 1; j < n; j++){
                sol[i] ^= sol[j] & es[x][j];
            }
        }
    }


    // double checker
    for (int x = 0; x < m; x++){
        int res = 0;
        for (int i = 0; i < n; i++){
            cout << sol[i] << ";" << es_base[x][i] << " ";
            res ^= sol[i] & es_base[x][i];
        }
        cout << res << "=" << expected[x] << "\n";
        if (res != expected[x]) {
            for (int i = 0; i < n; i++){
                cout << numbers[i] << ";";
            }
            cout << _d << "\n";
            return 0;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    es_base = vector<vector<int>>(m, vector<int>(n+1));
    sol = vector<int>(n);
    numbers = vector<ull>(n);
    for (int i = 0; i < n; i++){
        ull a; cin >> a;
        numbers[i] = a;
        for (int j = 0; j < m; j++){
            es_base[j][i] = a & 1;
            a >>= 1;
        }
    }
    // input
    while (q--){
        // cout << "q: " << q << "\n";
        ull d;
        cin >> d;
        cout << (gauss(d) ? "TAK\n" : "NIE\n");
        
    }
    return 0;      
}
