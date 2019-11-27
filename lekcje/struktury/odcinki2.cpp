#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct sumtree {
    int n = 1;
    vector<T> elements;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        elements.resize(n);
        n >>= 1;
    }
    void insert(int i, T x){
        i += n;
        elements[i] = x;
        while (i > 1){
            i >>= 1;
            elements[i] = elements[2*i] + elements[2*i+1];
        }
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid) result += _read(a, b, l, mid, 2*i);
        if (b >= mid + 1) result += _read(a, b, mid + 1, r, 2*i + 1);
        return result;
    }
    T read(int a, int b){
        if (b < a) return 0;
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

template<typename T>
struct Sumtree {
    int n = 1;
    vector<T> elements;
    Sumtree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        elements.resize(n);
        n >>= 1;
    }
    void insert(int i, T x){
        i += n;
        elements[i] = x;
        while (i > 1){
            i >>= 1;
            elements[i] = elements[2*i] + elements[2*i+1];
        }
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid) result += _read(a, b, l, mid, 2*i);
        if (b >= mid + 1) result += _read(a, b, mid + 1, r, 2*i + 1);
        return result;
    }
    T read(int a, int b){
        if (b < a) return 0;
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
    }
    void insert(int i, T x){
        i += n;
        elements[i] = x;
        while (i > 1){
            i >>= 1;
            elements[i] = elements[2*i] + elements[2*i+1];
        }
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
        //    return elements[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid) // result += _read(a, b, l, mid, 2*i);
        if (b >= mid + 1) // result += _read(a, b, mid + 1, r, 2*i + 1);
        return result;
    }
    T read(int a, int b){
        if (b < a) return 0;
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
    Sumtree<int> s(n);
    result<int> res(n);
    string seq; cin >> seq;
    for (int i = 0; i < n; i++){
        if (s[i] == 'P'){
            t.insert(i, 1);
        } 
    }
    cout << xd << "\n";
    
    
    return 0;
}
