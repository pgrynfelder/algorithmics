#include<bits/stdc++.h>
using namespace std;

bool hasseven(int a){
    while (a != 0){
        if ( a % 10 == 7){
            return true;
        }
        a /= 10;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    while (a <= b){
        if (a % 7 == 0 or hasseven(a)){
            cout << "plum\n";
        }
        else {
            cout << a << '\n';
        }
        a++;
    }
    return 0;
}
 