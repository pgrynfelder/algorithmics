#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct tree {
    int n = 1;
    int s;
    vector<T> elements;
    tree(int _n){
        while (n < _n){
            n *= 2;
        }
        n*=2;
        elements.resize(n);
        n /= 2;
    }
    void add(int a, int b, int l, int r, int i, T toadd){
        if (a <= l and r <= b){
            elements[i] += toadd;
            return;
        }
        int mid = (l+r)/2;
        if (a <= mid) add(a, b, l, mid, 2*i, toadd);
        if (mid + 1 <= b) add(a, b, mid + 1, r, 2*i+1, toadd);
        return;
    }
    T read(int i){
        i += n;
        T result = 0;
        while (i != 0){
            result += elements[i];
            i/=2;
        }
        return result;
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
    int n, m;
    cin >> n >> m;
    tree<ll> T(n);
    while (m-->0){
        char q;
        cin >> q;
        if (q == '+'){
            int a, b, x;
            cin >> a >> b >> x;
            T.add(a-1, b-1, 0, T.n-1, 1, x);
        }
        if (q == '?'){
            int i;
            cin >> i;
            cout << T.read(i-1) << '\n';
        }
    }
    // T.print();
    return 0;
}
/*
10 5
+ 1 5 2
? 4
+ 2 8 99
? 3
? 9
*/