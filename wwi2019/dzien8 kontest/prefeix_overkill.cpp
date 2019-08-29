#include<bits/stdc++.h>
using namespace std;


constexpr int N = 1e6+7;
int PS[2*N];
string word;

void knp(){
    PS[0] = -1;
    PS[1] = 0;
    for (int i = 2; i < word.size(); i++){
        int candidate = PS[i-1];
        while (candidate >= 0 and word[candidate+1] != word[i]){
            candidate = PS[candidate];
        }
        PS[i] = candidate + 1;
    }
}

template<typename T>
struct tree {
    int n = 1;
    vector<T> elements;
    vector<T> topropagate;
    tree (int _n){
        while (n < _n){
            n = n << 1;
        }
        n = n << 1;
        elements.resize(n);
        topropagate.resize(n);
        n = n >> 1;
    }

    void _add(int a, int b, int l, int r, int i, T x){
        if (a <= l and r <= b){
            elements[i] += x*(r-l+1); // have to account for adding on an interval
            topropagate[i] += x*(r-l+1)/2;
            return;
        }
        int mid = (l+r)/2;
        if (a <= mid or mid + 1 <= b){
            topropagate[2*i] += topropagate[i]/2;
            topropagate[2*i+1] += topropagate[i]/2;
            elements[2*i] += topropagate[i];
            elements[2*i+1] += topropagate[i];
            topropagate[i] = 0;
        }
        if (a <= mid){
            _add(a, b, l, mid, i*2, x);
        }
        if (mid + 1 <= b){
            _add(a, b, mid+1, r, i*2+1, x);
        }
        elements[i] = elements[i*2] + elements[i*2+1];
    }
    void add(int a, int b, T x) { _add(a, b, 0, n-1, 1, x);}

    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        if (a <= mid or mid + 1 <= b){
            topropagate[2*i] += topropagate[i]/2;
            topropagate[2*i+1] += topropagate[i]/2;
            elements[2*i] += topropagate[i];
            elements[2*i+1] += topropagate[i];
            topropagate[i] = 0;
        }
        T result = 0;
        if (a <= mid){
            result += _read(a, b, l, mid, i*2);
        }
        if (mid + 1 <= b){
            result += _read(a, b, mid+1, r, i*2+1);
        }
        return result;
    }
    T read(int a, int b) { return _read(a, b, 0, n-1, 1);}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    // cin >> b >> a;
    // word = "$" + b + "#" + a;
    // knp();
    // for (int i = b.size() + 2; i < a.size() + b.size() + 2; i++){
    //     cout << PS[i] << ' ';
    // }
    // cout << '\n';

    tree<int> T(8);
    T.add(1,7, +1);
    cout <<T.read(0,3) << '\n';
    return 0;
}
