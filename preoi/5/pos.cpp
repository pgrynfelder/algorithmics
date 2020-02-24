#include<bits/stdc++.h>
using namespace std;

int n, m, q;
template<typename T>
struct Tree {
    int n = 1;
    vector<T> t;
    vector<bool> flag;
    Tree (int _n){
        while (n < _n) n <<= 1;
        t.resize(n << 1, 1);
        flag.resize(n);
    }
    void insert(int i, T x){
        i += n;
        t[i] = x % m;
        while (i > 1){
            i >>= 1;
            t[i] = (long long)t[i << 1] * t[(i << 1) + 1] % m;
        }
    }
    void dislike(int i){
        flag[i] = true;
        i += n;
        i >>= 1;
        t[i] = 1;
        if (!flag[(i << 1) - n]) t[i] = (long long)t[i] * t[(i << 1)] % m;
        if (!flag[(i << 1) + 1 - n]) t[i] = (long long)t[i] * t[(i << 1) + 1] % m;
        while (i > 1){
            i >>= 1;
            t[i] = (long long)t[i << 1] * t[(i << 1) + 1] % m;
        }
    }
    void like(int i){
        flag[i] = false;
        i += n;
        i >>= 1;
        t[i] = 1;
        if (!flag[(i << 1) - n]) t[i] = (long long)t[i] * t[(i << 1)] % m;
        if (!flag[(i << 1) + 1 - n]) t[i] = (long long)t[i] * t[(i << 1) + 1] % m;
        while (i > 1){
            i >>= 1;
            t[i] = (long long)t[i << 1] * t[(i << 1) + 1] % m;
        }   
    }
    /*
    void print(){
        int m = 1;
        for (int i = 1; i <= (n << 1); i++){

            if (i == (m << 1)){
                cout << "\n";
                m <<= 1;
            }
            cout << t[i] << " ";
        }
        cout << "\n";
    }*/
    /* // obsolete 
    T read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return t[i];
        }
        T res = 1;
        if (a <= mid) res = (long long)res * read(a, b, l, mid, i << 1) % m;
        if (b >= mid + 1) res = (long long)res * read(a, b, mid + 1, r, (i << 1) + 1) % m;
        return res; 
    }
    */
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    Tree T = Tree<int>(n);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        T.insert(i, a);
    }
    // T.print();
    stack<int> disliked;
    for (int j = 0; j < q; j++){
        int c; cin >> c;
        if (c == 0){
            int p, w;
            cin >> p >> w;
            T.insert(p-1, w);
        }
        else {
            int k; cin >> k;
            for (int h = 0; h < k; h++){
                int b; cin >> b;
                // dislike b-1
                T.dislike(b - 1);
                disliked.push(b);
            }
            cout << T.t[1] << "\n";
            // T.print();
            while (!disliked.empty()){
                T.like(disliked.top() - 1);
                disliked.pop();
            }
        }
    }

    return 0;
}

/*
5 15 6
2 6 3 2 7
1 3 1 5 3
0 2 0
1 2 5 1
0 3 1
0 2 5
1 2 1 5
*/


