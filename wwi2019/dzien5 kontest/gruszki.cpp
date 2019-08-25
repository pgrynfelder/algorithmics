#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct tree {
    int n = 1;
    vector<T> elements;
    tree (int _n){
        while (n < _n){
            n*=2;
        }
        n *= 2;
        elements.resize(n);
        n /= 2;
    }

    void add(int i, T x){
        i += n;
        elements[i] += x;
        i /= 2;
        while (i > 0){
            elements[i] = max(elements[i*2], elements[i*2+1]);
            i /= 2;
        }
    }

    int find(T x){
        int i = 1;
        while (i < n){
            if (elements[i*2] >= x){
                i = i * 2;
            }
            else if (elements[i*2+1] >= x){
                i = i * 2 + 1;
            }
            else {
                return -2;
            }
        }
        return i - n;
    }

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
    int n, m;
    cin >> n;
    tree<int> T(n);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        T.add(i, a);
    }
    //T.print();
    cin >> m;
    while (m--){
        int a;
        cin >> a;
        int i = T.find(a);
        T.add(i, -a);
        cout << i + 1 << ' ';
    }
    return 0;
}
/* 
5
3 1 5 6 5
6
5 2 2 1 5 7
*/
