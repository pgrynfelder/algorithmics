#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct segsegtree {
    int n = 1;
    vector<T> elements;
    vector<T> topropagate;
    segsegtree(int _n){
        while (n < _n){
            n *= 2;
        }
        n*=2;
        elements.resize(n);
        topropagate.resize(n);
        n /= 2;
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result =  0;
        if (a <= mid or mid + 1 <= b){
            elements[2*i] += topropagate[i];
            elements[2*i+1] += topropagate[i];
            topropagate[2*i] += topropagate[i];
            topropagate[2*i+1] += topropagate[i];
            topropagate[i] = 0;
        }
        if (a <= mid) result = max(result, _read(a, b, l, mid, 2*i));
        if (mid + 1 <= b) result = max(result, _read(a, b, mid + 1, r, 2*i+1));
        return result;
    }
    T read(int a, int b){
        return _read(a, b, 0, n-1, 1);
    }
    void _insert(int a, int b, int l, int r, int i, T x){
        if (a <= l and r <= b){
            elements[i] += x;
            topropagate[i] += x;
            return;
        }
        int mid = (l+r)/2;
        if (a <= mid or mid + 1 <= b){
            elements[2*i] += topropagate[i];
            elements[2*i+1] += topropagate[i];
            topropagate[2*i] += topropagate[i];
            topropagate[2*i+1] += topropagate[i];
            topropagate[i] = 0;
        }
        if (a <= mid) _insert(a, b, l, mid, 2*i, x);
        if (mid + 1 <= b) _insert(a, b, mid + 1, r, 2*i+1, x);
        
        elements[i] = max(elements[2*i], elements[2*i+1]);
        
        return;
    }
    void insert(int a, int b, T x){
        _insert(a, b, 0, n-1, 1, x);
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    segsegtree<int> T(8);
    int n;
    cin >> n;
    while (n-->0){
        int lol;
        cin >> lol;
        if (lol){
            int a, b, c;
            cin >> a >> b >> c;
            T.insert(a-1, b-1, c);
        }
        else {    
            int a, b;
            cin >> a >> b;
            cout << T.read(a-1,b-1) << '\n';
        }
    }
    //T.print();
    return 0;
}
/*
3
1 2 1
0
*/