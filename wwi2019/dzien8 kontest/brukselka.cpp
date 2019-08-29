#include<bits/stdc++.h>
using namespace std;


template<typename T>
struct tree {
    int n = 1;
    vector<T> elements;
    tree (int _n){
        while (n < _n){
            n = n << 1;
        }
        n = n << 1;
        elements.resize(n);
        n = n >> 1;
    }
    void set(int i, T x) { 
        i += n;
        elements[i] = x;
        i /= 2;
        while (i!=0){
            elements[i] = max(elements[i*2], elements[i*2+1]);
            i /= 2;
        }
    }

    T _read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result = 0;
        if (a <= mid){
            result = max(result, _read(a, b, l, mid, i*2));
        }
        if (mid + 1 <= b){
            result = max(result,_read(a, b, mid+1, r, i*2+1));
        }
        return result;
    }
    T read(int a, int b) { return _read(a, b, 0, n-1, 1);}

    void print(){
        for (int j = 1; j < 2*n; j *= 2){
            for (int i = j; i < j*2; i++){
                cout << elements[i] << ' ';
            }
            cout << '\n';
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    tree<int> dist(n+2);
    vector<int> days(n);
    for (int i = 0; i < n; i++){
        cin >> days[i];
    }
    //cout << "Here" << endl;
    for (int i = n - 1; i >= 0; i--){
        int f = dist.read(min(i + 1 + days[i], dist.n-1), dist.n-1);
        dist.set(i, f+1);
    }
    //cout << "Here" << endl;
    cout << dist.read(0, n-1) << '\n';

    //dist.print();

    return 0;
}
