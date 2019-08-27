#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
};

struct edge {
    int top, bottom, x;
    int t; // true 
    edge(int _bottom, int _top, int _x, int _t){
        top = _top; bottom = _bottom; x = _x; t = _t;
    }
};

bool compare(const edge &a, const edge &b){
    if (a.x == b.x and a.t == 1){
        return true;
    }
    return a.x < b.x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<edge> v;
    int q;
    cin >> q;
    segsegtree<int> T(400007);
    const int fix = 200000;
    while (q-->0){
        int a, b, c, d; // lewy dolny / prawy gorny
        cin >> a >> b >> c >> d;
        a += fix; b += fix; c+= fix; d+= fix;
        v.push_back({b,d,a,+1});
        v.push_back({b,d,c,-1});
    }
    sort(v.begin(), v.end(), compare);
    int mx = 0;
    for (auto e : v){
        T.insert(e.bottom, e.top, e.t);
        mx = max(mx, T.read(0,T.n-1));
    }
    cout << mx << '\n';

    return 0;
}
