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
        i += n;
        elements[i] = x;
        while (i > 1){
            i >>= 1;
            elements[i] = max(elements[2*i], elements[2*i+1]);
        }
    }
    T read(){
        return elements[1];
    }
};


int n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    Tree<int> t(n);
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        t.insert(i, x);
    }
    cout << t.read() << "\n";
    while (m-->0){
        int i; cin >> i;
        int x; cin >> x;
        t.insert(i, x);
        cout << t.read() << "\n";
    }
    return 0;
}
