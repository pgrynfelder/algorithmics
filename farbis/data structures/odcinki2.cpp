#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Tree {
    int n = 1;
    
    vector<T> begins;
    vector<T> ends;
    vector<T> res;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        begins.resize(n);
        ends.resize(n);
        res.resize(n);
        n >>= 1;
    }
    void invert_begin(int i){
        i += n;
        begins[i] ^= 1;
        while (i > 1){
            i >>= 1;
            begins[i] = begins[2*i] + begins[2*i+1];
            res[i] = res[2*i] + res[2*i+1] + begins[2*i] * ends[2*i + 1];
        }
    }
    void invert_end(int i){
        i += n;
        ends[i] ^= 1;
        while (i > 1){
            i >>= 1;
            ends[i] = ends[2*i] + ends[2*i+1];
            res[i] = res[2*i] + res[2*i+1] + begins[2*i] * ends[2*i + 1];
        }
    }
    T count_begins(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return begins[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid) result += count_begins(a, b, l, mid, 2*i);
        if (b >= mid + 1) result += count_begins(a, b, mid + 1, r, 2*i + 1);
        return result;
    }
    T count_ends(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return ends[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid) result += count_ends(a, b, l, mid, 2*i);
        if (b >= mid + 1) result += count_ends(a, b, mid + 1, r, 2*i + 1);
        return result;
    }
    T read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return res[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid and mid + 1 <= b)
            return 
               read(a, b, l, mid, 2*i)
             + read(a, b, mid + 1, r, 2*i + 1)
             + count_begins(a, b, l, mid, 2*i) * count_ends(a, b, mid + 1, r, 2*i+1);
        if (a <= mid)
            return read(a, b, l, mid, 2*i);
        if (b >= mid + 1)
            return read(a, b, mid + 1, r, 2*i + 1);
        return 0;
    }
    void print(){
         int i = 1;
         int m = 1;
         int lim = n*2;
         while (i < lim){
            while (i < m){
                cout << begins[i] << ";" << ends[i] << ";" << res[i] << ' ';
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
    string seq; cin >> seq;
    for (int i = 0; i < n; i++){
        if (seq[i] == 'P'){
            t.invert_begin(i);
        } 
        else {
            t.invert_end(i);
        }
    }
    for (int i = 0; i < m; i++){
        char c;
        cin >> c; 
        if (c == '?'){
            int a, b;
            cin >> a >> b;
            cout << t.read(a-1, b-1, 0, t.n - 1, 1) << "\n";
        }
        else {
            int a;
            cin >> a;
            t.invert_begin(a-1); t.invert_end(a-1);
        }
    }
    // t.print();
        
        
    return 0;
}
