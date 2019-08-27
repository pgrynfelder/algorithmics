#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
struct segsegtree {
    int n = 1;
    vector<T> elements;
    vector<T> topropagate;
    vector<int> maxleafi;
    segsegtree(int _n){
        while (n < _n){
            n *= 2;
        }
        n*=2;
        elements.resize(n);
        topropagate.resize(n);
        maxleafi.resize(n);
        for (int i = n/2; i < n; i++){
            maxleafi[i] = i-n/2;
        }
        n /= 2;
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        // if (T == ll){
            T result = LONG_LONG_MIN;
        // }
        // else {
        //     T result = INT_MIN;
        // }
        if (a <= mid or mid + 1 <= b){
            elements[2*i] += topropagate[i];
            elements[2*i+1] += topropagate[i];
            topropagate[2*i] += topropagate[i];
            topropagate[2*i+1] += topropagate[i];
            topropagate[i] = 0;
        }
        if (a <= mid){
            int x = _read(a, b, l, mid, 2*i);
            if (x > result){
                maxleafi[i] = maxleafi[2*i];
                result = x;
            }
        }
        if (mid + 1 <= b){
            int x = _read(a, b, mid + 1, r, 2*i+1);
            if (x > result){
                maxleafi[i] = maxleafi[2*i+1];
                result = x;
            }
        }
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
        
        if (elements[2*i] > elements[2*i+1]){
            elements[i] = elements[2*i];
            maxleafi[i] = maxleafi[2*i];
        }
        else {
            elements[i] = elements[2*i+1];
            maxleafi[i] = maxleafi[2*i+1];
        }
        
        return;
    }
    void insert(int a, int b, T x){
        _insert(a, b, 0, n-1, 1, x);
    }
    
};

template<typename T>
struct sumtree {
    int n = 1;
    vector<T> elements;
    sumtree(int _n){
        while (n < _n){
            n *= 2;
        }
        n*=2;
        elements.resize(n);
        n /= 2;
    }
    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result =  0;
        if (a <= mid) result += _read(a, b, l, mid, 2*i);
        if (mid + 1 <= b) result += _read(a, b, mid + 1, r, 2*i+1);
        return result;
    }
    T read(int a, int b){
        return _read(a, b, 0, n-1, 1);
    }
    void push(int i, T x){
        i += n;
        while (i != 0){
            elements[i] += x;
            i/=2;
        }
        return;
    }
};

segsegtree<ll> *T;
sumtree<int> *G;
int limit;
void inicjuj(int n, int k, int *D){
    limit = k;
    T = new segsegtree<ll>(n);
    G = new sumtree<int>(n);
    for (int i = 0; i < n; i++){
        T->insert(i, i, *(D+i));
    }
}
void podlej(int a, int b){
    T->insert(a, b , +1);
}
int dojrzale(int a, int b){
    while (T->read(0,T->n-1) >= limit){
        G->push(T->maxleafi[1], +1);
        T->insert(T->maxleafi[1], T->maxleafi[1], LONG_LONG_MIN);
    }
    return G->read(a, b);
}
