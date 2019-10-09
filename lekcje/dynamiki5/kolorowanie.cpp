#include<bits/stdc++.h>
using namespace std;

/* d(i, c) = ways to color index i with colour c
 * D(i) = [d(i, A), d(i, B), d(i, C)]
 *
 * zauwazmy, ze jezeli nie ma zadnych wymuszonych to mozemy zapisac
 * D(i) = M * D(i-1)
 * gdyz przejscie jest liniowe
 *
 * gdzie M to jakas macierz kwadratowa
 * w tym przypadku 
 * [ 0 1 1 
 *   1 0 1
 *   1 1 0 ]
 * 
 * wiec D(i) = M^k * D(i - k)
 *
 */
const int mod = 1e9 + 33;
int n, k;

struct M {
    vector<vector<int>> tab;
    int height, width;
    M(int _width, int _height){
        height = _height;
        width = _width;
        tab = vector<vector<int>>(width, vector<int>(height));
    }
    M operator* (M other){
        M xd = M(other.width, height); 
        for (int j = 0; j < xd.height; j++){
            for (int i = 0; i < xd.width; i++){
                for (int x = 0; x < width; x++){
                    xd.tab[i][j] = ((long long)xd.tab[i][j] + (long long)tab[x][j] * other.tab[i][x]) % mod;
                }
            }
        }
        return xd;
    }
    void print(){
        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                cout << tab[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

M power(M m, int n){
    M res = M(3, 3);
    res.tab[0][0] = res.tab[1][1] = res.tab[2][2] = 1;
    for(; n > 0; n >>= 1) {
        if(n & 1) {
            res = res * m;
        }
        m = m * m;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    M m = M(3,3);
    m.tab[1][0] = m.tab[2][0] = m.tab[0][1] = m.tab[2][1] = m.tab[0][2] = m.tab[1][2] = 1;
    
    cin >> n >> k;
    
    M def = M(1, 3);
    def.tab[0][0] = def.tab[0][1] = def.tab[0][2] = 1;
    
    vector<pair<int, char>> forced(k);
    for (int i = 0; i < k; i++){
        cin >> forced[i].first >> forced[i].second;
        forced[i].second -= 'A';
    }
    sort(forced.begin(), forced.end());

    return 0;
}
