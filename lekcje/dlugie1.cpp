#include<bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;
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

M power(M m, long long n){
    M res = M(m.width, m.height);
    for (int i = 0; i < res.width; i++) res.tab[i][i] = 1;
    while (n > 0) {
        if(n & 1) {
            res = res * m;
        }
        m = m * m;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    M xd(5, 5);
    xd.tab[1][2] = 1;
    xd.tab[2][3] = 1;
    xd.tab[3][1] = 1;
    xd.tab[3][4] = 1;
    xd.print();
    xd = xd * xd;
    xd.print();
    return 0;
}
 