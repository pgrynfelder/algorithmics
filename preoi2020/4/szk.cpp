#include<bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 7, inf = 1e9 + 7;

int fu[N], p[N], s[N], t[N][2];

void add(int i, int x){ // add x to i
    fu[x] = i;
    p[i] = max(p[i], t[x][0]);
    s[i] = min(s[i], t[x][1]);
}

template<typename T>
struct Tree {
    int n = 1;
    vector<T> t;
    vector<int> where;
    Tree (int _n){
        while(n < _n){
            n <<= 1;
        }
        t.resize(n << 1);
        where.resize(n << 1);
    }
    void insert(int i, T x, int pos){
        i += n;
        if (t[i] < x){
            t[i] = x;
            where[i] = pos;
        }
        else {
            return;
        }
        while(i > 1){
            i >>= 1;
            if (t[i << 1] > t[(i<<1) + 1]){
                t[i] = t[i << 1];
                where[i] = where[i << 1];
            }
            else {
                t[i] = t[(i << 1) + 1];
                where[i] = where[(i << 1) + 1];
            }
        }
    }
    pair<T, int> read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return {t[i], where[i]};
        }
        pair<T, int> res = {0,0};
        int mid = (l + r) / 2;
        if (a <= mid) res = max(res, read(a, b, l, mid, i << 1));
        if (b >= mid+1) res = max(res, read(a, b, mid + 1, r, (i << 1) + 1));
        return res;
    }
    pair<T, int> read(int a, int b){
        return read(a,b, 0, n-1, 1);
    }
};

map<int, int, greater<int>> m = {{0, 0}};
int n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    set<int> scale;
    Tree<int> tree(N << 1);
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        t[i][0] = a; t[i][1] = b;
        scale.insert(a); scale.insert(b);
    }
    while (!scale.empty()){
        m[*scale.begin()] = m.begin() -> second + 1;
        scale.erase(scale.begin());
    }
    for (int i = 1; i <= n; i++){
        t[i][0] = m[t[i][0]]; t[i][1] = m[t[i][1]];

        pair<int, int> xd = tree.read(0, t[i][1] - 1); // from padawans with powers less than our durability, choose one with the biggest durability
//        cout << xd.first << " " << xd.second << " ";
        if (xd.second != 0 and xd.first > t[i][0]){  // if chosen ones durability is satisfiable (ie > 0 at the same time)
            if (t[i][1] > p[fu[xd.second]] and t[i][0] < s[fu[xd.second]]){
                add(fu[xd.second], i);
                tree.insert(t[i][0], t[i][1], i);
                cout << "TAK\n";
            }
            else {
                cout << "NIE\n";
            }
        }
        else {
            fu[i] = i;
            p[i] = t[i][0]; s[i] = t[i][1];
            tree.insert(t[i][0], t[i][1], i);
            cout << "TAK\n";
        }
    }

    return 0;
}
