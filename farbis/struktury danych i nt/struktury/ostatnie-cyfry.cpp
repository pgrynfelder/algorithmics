#include<bits/stdc++.h>
using namespace std;

struct digits {
    vector<int> t;
    digits(){
        t = vector<int>(10);
    }
    int get(int i, int rot){
        return t[((i-rot) % 10 + 10) % 10];
    }
    void set(int i, int rot, int x){
        t[((i-rot) % 10 + 10) % 10] = x;
    }
    int sum(int rot){
        int result = 0;
        for (int i = 0; i < 10; i++){
            result += get(i, rot) * i;
            // cout << "summing " << get(i, rot) << " * " << i << "\n";
        } 
        return result;
    }
};

template<typename T>
struct Tree {
    int n = 1;
    vector<T> t;
    vector<int> rot;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        t.resize(n << 1);
        rot.resize(n << 1);
    }

    int read(int a, int b, int l, int r, int i){
        // cout << "reading (ablr) " << a << " " << b << " " << l << " " << r << "\n";
        if (a <= l and r <= b){
            return t[i].sum(rot[i]);
        }
        int mid = (l+r)/2;
        if (a <= mid or mid + 1 <= b){
            rot[2*i] = (rot[i] + rot[2*i]) % 10; rot[2*i + 1] = (rot[i] + rot[2*i + 1]) % 10;
            rot[i] = 0;
            for (int j = 0; j < 10; j++){
                t[i].set(j, 0, t[2*i].get(j, rot[2*i]) + t[2*i+1].get(j, rot[2*i+1]));
            }
            if (a <= mid and mid + 1 <= b){
                return read(a, b, l, mid, 2*i) + read(a, b, mid + 1, r, 2*i + 1);
            }
            else if (a <= mid){
                return read(a, b, l, mid, 2*i);
            }
            else {
                return read(a, b, mid + 1, r, 2*i + 1);
            }
        }
        return 0;
    }
    void rotate(int a, int b, int l, int r, int i, int x){
        if (a <= l and r <= b){
            rot[i] = (rot[i] + x) % 10;
            return;
        }
        int mid = (l+r)/2;
        if (a <= mid or mid + 1 <= b){
            rot[2*i] = (rot[i] + rot[2*i]) % 10; rot[2*i + 1] = (rot[i] + rot[2*i + 1]) % 10;
            rot[i] = 0;
            if (a <= mid){
                rotate(a, b, l, mid, 2*i, x);
            }
            if (mid + 1 <= b) {
                rotate(a, b, mid + 1, r, 2*i + 1, x);
            }
            for (int j = 0; j < 10; j++){
                t[i].set(j, 0, t[2*i].get(j, rot[2*i]) + t[2*i+1].get(j, rot[2*i+1]));
            }
        }
        return;
    }
    void init(){
        int i = n-1;
        while (i > 0){
            for (int j = 0; j < 10; j++){
                t[i].set(j, 0, t[2*i].get(j, rot[2*i]) + t[2*i+1].get(j, rot[2*i+1]));
            }
            i--;
        }
    }
    
    void print(){
        int i = 1;
        int m = 1;
        int lim = n<<1;
        while (i < lim){
            while (i < m){
                cout << t[i].sum(rot[i]) << ";" << rot[i]<< ' ';
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
    Tree<digits> t(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x; x %= 10;
        t.t[t.n+i].set(x, 0, 1);
    }
    // t.print();
    t.init();
    // t.print();
    while (m--){
        char c; cin >> c;
        if (c == '?'){
            int a, b;
            cin >> a >> b;
            cout << t.read(a-1, b-1, 0, t.n-1, 1) << "\n";
        }
        else {
            int a, b, x;
            cin >> a >> b >> x;
            x %= 10;
            t.rotate(a-1, b-1, 0, t.n-1, 1, x);
        }
    }
    // t.print();
    return 0;
}
