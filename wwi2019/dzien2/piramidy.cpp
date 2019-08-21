#include<bits/stdc++.h>
using namespace std;

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
    T read(int a, int b, int l, int r, int i){
        if (a <= l and r <= b){
            return elements[i];
        }
        int mid = (l+r)/2;
        T result =  0;
        if (a <= mid) result += read(a, b, l, mid, 2*i);
        if (mid + 1 <= b) result += read(a, b, mid + 1, r, 2*i+1);
        return result;
    }
    void push(int i, T x){
        i += n;
        while (i != 0){
            elements[i] += x;
            i/=2;
        }
        return;
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

    int q;
    cin >> q;
    vector<int> stones(q);
    vector<int> sorted(q);
    while (q-->0){
        int a;
        cin >> a;
        stones[q] = sorted[q] = a;
    }
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> dict;
    int last = 1;
    dict[*sorted.begin()] = last;
    for (auto i = sorted.begin()+1; i != sorted.end(); i++){
        if (!(*i == *(i-1))){
            last += 1;
        }
        dict[*i] = last;
    }
    
    for (auto i = stones.begin(); i != stones.end(); i++){
        *i = dict[*i];
    }
    reverse(stones.begin(), stones.end());

    tree<int> T(1e6+1);

    for (auto stone : stones){
        T.push(stone, +1);
        cout << T.read(0, stone-1, 0, T.n-1, 1) << '\n';
    }
    return 0;
}
/*
6 
5 3 6 10 2 4
*/
