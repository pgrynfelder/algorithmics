#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> i;
    srand(i);
    cout << "10 10\n";
    int y = 10;
    while (y-->0){
        int x = 10;
        while (x-->0){
            if (rand()%2){
                cout << '#';
            }
            else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}
