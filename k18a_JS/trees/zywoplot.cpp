#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
    vector<int> tree;
    int n;
    T (int _size){
        int size = 1;
        n = 0;
        while (size < _size << 1){
            n++;
            size = size << 1;
        }
        tree.reserve(size+1);
    }
    void add(int i, int x){
        i += (1 << (n-1)) - 1;
        while (i > 0){
            tree[i] += x;
            i /= 2;
        }
    }
    // a, b - to search, c, d, i - helper params
    int read(int a, int b, int c, int d, int i){
        if (a > d or b < c) {
            return 0;
        }
        else if (a <= c and d <= b){
            return tree[i];
        }
        else {
            return read(a, b, c, (c+d)/2, i*2) + read(a, b, (c+d)/2+1, d, i*2+1);
        }
    }
};

int last[1000000]; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    T toh = T(1000000);
    for(int i = 1; i <= n; i++){
        int h;
        cin >> h;
        toh.add(h, +1);
        last[i] = h;
    }
    while (q-->0){
        string s;
        cin >> s;
        if (s == "pyt"){
            int h;
            cin >> h;
            cout << toh.read(h, 1000000, 1, 1 << (toh.n-1), 1) << '\n';
        }
        if (s == "mod"){
            int i,h;
            cin >> i >> h;
            toh.add(last[i], -1);
            //cout << i << ": " << last[i] << ' ';
            toh.add(h, +1);
            last[i] = h;
        }
    }
    return 0;
}