#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Tree {
    int n = 1;
    vector<T> elements;
    Tree(int _n){
        while (n < _n){
            n <<= 1;
        }
        n <<= 1;
        elements.resize(n);
        n >>= 1;
    }
    Tree(){}
    void insert(int i, T x){
        i += n;
        elements[i] = x;
        while (i > 1){
            i >>= 1;
            elements[i] = elements[2*i] + elements[2*i+1];
        }
    }
    void print(){
        int i = 1;
        int m = 1;
        int lim = n<<1;
        while (i < lim){
            while (i < m){
                cout << elements[i] << ' ';
                i++;
            }
            m *= 2;
            cout << "\n";
        }
    }
    T find_biggest(int x){
        int i = 1; 
        while (i < n){
            if (elements[i<<1] >= x){
                i <<= 1;
            } else {
                x -= elements[i<<1];
                i = (i<<1) + 1;
            }
       //     cout << i << " ";
        }
        return i - n;
    }
};
// the tree's indexed from 0 to n-1

int n, m, i;
const int N = 2e5 + 7;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    Tree<int> T(N);
    while (n--){
        cin >> m >> i;
        if (m == 1){
            T.insert(i, 1);
        } else if (m == 2){
            T.insert(i, 0);
        } else {
        //    T.print();
            cout << T.find_biggest(i) << "\n";
        }
    }
    return 0;
}
