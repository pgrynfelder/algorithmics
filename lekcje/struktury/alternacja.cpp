#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct Tree {
    int n = 1;
    vector<T> elements;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        elements.resize(n);
        n >>= 1;
        // cout << n << "\n";
    }
    void insert(int i, T x){
    
    }
};


int n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    Tree<pair<int,int>> t(n);
    return 0;
}
