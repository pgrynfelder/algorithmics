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
    vector<int> expected(m);
    for (int j = 0; j < m; j++){
        expected[j] = es[j][n] = d & 1;
        d >>= 1;
    }

    vector<int> where(n, -1);
    for (int col = 0, row = 0; col < n; col++){
        for (int y = row + 1; y < m; y++){
            if (es[y][col] > es[row][col]){
                swap(es[y], es[row]);
            }
        }
        if (es[row][col] == 0){
            continue;
        }
        where[col] = row;
        for (int y = row + 1; y < m; y++){
            if (es[y][col] == 1){
                for (int x = col; x <= n; x++){
                    es[y][x] ^= es[row][x];
                }
            }
        }
        row++;    
    }
    for (int x = 0; x < m; x++){
        for (int i = 0; i < n + 1; i++){
            cout << es[x][i] << " ";
        }
        cout << "\n";
    }

    for (int col = n-1; col >= 0; col--){
        if (where[col] == -1){
            sol[col] = 0;
        }
        else {
            int row = where[col];
            sol[col] = es[row][n];
            for (int x = col+1; x < n; x++){
                sol[col] ^= es[row][x] & sol[x];
            }

        }
    }
    // double checker
    for (int x = 0; x < m; x++){
        int res = 0;
        for (int i = 0; i < n; i++){
            // cout << sol[i] << ";" << es_base[x][i] << " ";
            res ^= sol[i] & es_base[x][i];
        }
        // cout << res << "=" << expected[x] << "\n";
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

/*

8 1
144
36
180
203
125
201
0
146
125

*/
