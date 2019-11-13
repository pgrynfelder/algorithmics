#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll inf = LONG_LONG_MAX - 5;
template<typename T>
struct tree {
    int n = 1;
    vector<T> elements;
    vector<T> topropagate;
    tree(int _n){
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
        T result =  inf;
        if (a <= mid or mid + 1 <= b){
            elements[2*i] += topropagate[i];
            elements[2*i+1] += topropagate[i];
            topropagate[2*i] += topropagate[i];
            topropagate[2*i+1] += topropagate[i];
            topropagate[i] = 0;
        }
        if (a <= mid) result = min(result, _read(a, b, l, mid, 2*i));
        if (mid + 1 <= b) result = min(result, _read(a, b, mid + 1, r, 2*i+1));
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
        
        elements[i] = min(elements[2*i], elements[2*i+1]);
        
        return;
    }
    void insert(int a, int b, T x){
        _insert(a, b, 0, n-1, 1, x);
    } 
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	tree<ll> t(n);
	for (int i = 0; i < n; i++){
		ll xd; cin >> xd;
        t.insert(i, i, xd);    
	}
    while (q-->0){
        char s; int a, b; ll xd;
        cin >> s >> a >> b;
        a--; b--;
        if (s == '?'){
            cout << t.read(a, b) << "\n";
        } else {
            cin >> xd;
            t.insert(a, b, xd);
        }
    }
	return 0;
}
