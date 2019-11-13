#include<bits/stdc++.h>
using namespace std;

const long long inf = LONG_LONG_MAX-1;
template<typename T>
struct Tree {
    int n = 1;
    vector<T> elements;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        elements.resize(n, -inf);
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
    void add(int i, T x){
        insert(i, x + elements[n + i]);
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result = -inf;
        if (a <= mid)
            result = max(result, _read(a, b, l, mid, 2*i));
        if (b >= mid + 1)
            result = max(result, _read(a, b, mid+1, r, 2*i + 1));
        return result;
    }
    T read(int a, int b){
        return _read(a, b, 0, n-1, 1);
    }    
    void print(){
         int i = 1;
         int m = 1;
         int lim = n*2;
         while (i < lim){
            while (i < m){
                cout << elements[i] << ' ';
                i++;
            }
            m *= 2;
            cout << "\n";
         }
    }
};


int n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    Tree<long long> t(n);
    for (int i = 0; i < n; i++){
        long long x; cin >> x;
        t.insert(i, x);
    }
    // t.print();
    while (m-->0){
        char c; cin >> c;
        if  (c == '+'){
            int i; cin >> i; i--;
            long long x; cin >> x;
            t.add(i, x);
        }
        else {
            int a, b; cin >> a >> b;
            // t.print();
            cout << t.read(a-1, b-1) << "\n";
        }
    }
    return 0;
}
