#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int seed;
    cin >> seed;
    srand(seed);
    int n = 1+rand()%20;
    cout << n << '\n';
    while(n-->0){
        int lol = rand()%2;
        if (lol){
            cout << lol << '\n';
            int a = 1+rand()%8;
            int b = a + rand()%(8 - a + 1);
            cout << a << ' ' << b << ' ' << rand() % 10 << '\n';
        }
        else {
            cout << lol << '\n';
            int a = 1+rand()%8;
            int b = a + rand()%(8 - a + 1);
            cout << a << ' ' << b << '\n';
        }
    }
    return 0;
}
