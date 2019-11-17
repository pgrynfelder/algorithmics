#include<bits/stdc++.h>
#include <time.h>  
using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     srand(time(0));
//     int n = rand() % (1000) + 1;
//     int m = rand() % (1000) + 1;
//     int k = rand() % (n*m-1 - (n+m-1) + 1) + (n+m-1);
//     cout << n << " " << m << " " << k << "\n";
//     return 0;
// }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n = rand() % (15) + 1;
    int m = rand() % (15) + 1;
    int k = rand() % (n*m-1 - (n+m-1) + 1) + (n+m-1);
    cout << n << " " << m << " " << k << "\n";
    return 0;
}
