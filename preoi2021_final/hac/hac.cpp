/*
PREOI 2021 FINAL
HAC

subtask 1
*/


#include <bits/stdc++.h>
using namespace std;

int M, N, W;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    if (M == 200) {
        N = 102, W = 7;
        cout << N << " " << W << "\n";
        for (int i = 1; i <= 2; i++) cout << "2 ";
        for (int i = 1; i <= 100; i++) cout << "5 ";
        return 0;
    } else if (M < 200) {
        N = M + 1, W = 201;
        cout << N << " " << W << "\n";
        for (int i = 1; i < N; i++) cout << "1 ";
        cout << "200 ";
        return 0;
    } 
    cout << "-1";
    return 0;
}