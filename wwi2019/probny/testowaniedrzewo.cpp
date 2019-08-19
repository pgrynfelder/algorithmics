#include<bits/stdc++.h>

using namespace std;

int randrange(int a, int b){
    return a + (rand() % (b - a + 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    //cin >> N;
    N = 101;
    srand(N);
    int s = randrange(10000, 100009);
    cout << s << '\n';
    for (int i = 2; i <= s; i++){
        cout << randrange(max(1, i - 100), i - 1) << ' ' << i << "\n";
    }
    return 0;
}