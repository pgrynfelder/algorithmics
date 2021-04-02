/* wiadra aka buckets */
#include<bits/stdc++.h>
using namespace std;
constexpr long long inf = LONG_LONG_MAX - 7;

template<typename T>
struct Tree {
    int n = 1;
    vector<T> t;
    vector<T> mod;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        t.resize(n);
        mod.resize(n);
        n >>= 1;
    }
    Tree(){}
    void add(int a, int b, int l, int r, int i, T x){
        // cout << a << " " << l << " " << r << " " << b << "\n";
        if (a <= l and r <= b){
            mod[i] += x;
            // cout << "stopped\n";
            return;
        }

        int mid = (l+r)/2;
        if (a <= mid) add(a, b, l, mid, i << 1, x);
        if (mid + 1 <= b) add(a, b, mid + 1, r, (i << 1) + 1, x);

        t[i] = max(t[i<<1] + mod[i<<1], t[(i<<1)+1] + mod[(i<<1)+1]);
    }
    void insert(int i, T x){
        i += n;
        t[i] = x;
        while (i > 1){
            i >>= 1;
            t[i] = max(t[i<<1] + mod[i<<1], t[(i<<1)+1] + mod[(i<<1)+1]);
        }
    }
    void print(){
        int i = 1;
        int m = 1;
        int lim = n<<1;
        while (i < lim){
            int j = i;
            while (j < m){
                cout << t[j] << ' ';
                j++;
            }
            cout << "\n";
            while (i < m){
                cout << mod[i] << ' ';
                i++;
            }
            m *= 2;
            cout << "\n";
        }
    }
    int find_biggest(){
        int i = 1;
        while (i < n){
            if (t[i<<1] + mod[i<<1] >= t[(i<<1)+1] + mod[(i<<1)+1]){
                i <<= 1;
            }
            else {
                i = (i << 1) + 1;
            }
        }
        return i - n;
    }
};
int res[200007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Tree<long long> t = Tree<long long>(n);
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        t.insert(i, -x);
    }
    for (int i = n; i < t.n; i++){
        t.insert(i, -inf);
    }
    // t.print();
    for (int i = 1; i <= m; i++){
        int a, b;
        long long x;
        cin >> a >> b >> x;
        t.add(a - 1, b - 1, 0, t.n-1, 1, x);
        while (t.t[1] + t.mod[1] >= 0){
            int j = t.find_biggest();
            t.insert(j, -inf);
            res[j + 1] = i;
        }
    }
    // t.print();
    for (int i = 1; i <= n; i++){
        if (res[i]){
            cout << res[i] << "\n";
        }
        else {
            cout << "NIE\n";
        }
    }
    return 0;
}
