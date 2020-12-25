/*
graf reszt
#grafreszt
#reszty
#reszta
#nt
#grafy
*/
#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;
constexpr long long oo = 1e16 + 7;
long long dist[N];
int src[N];
int edge[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1){
        cout << 1; return 0;
    }

    for (int i = 0; i < n; i++){
        dist[i] = oo;
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
    
    for (int x = 1; x <= min(9, n-1); x++){
        dist[x] = x;
        edge[x] = x;
        Q.emplace(x, x);
    }

    while (!Q.empty()){
        long long d = Q.top().first;
        int x = Q.top().second;
        Q.pop();
        if (x == 0){
            break;
        }
        for (int i = 0; i <= 9; i++){
            int y = (x * 10 + i) % n;
            if (d + i < dist[y]){
                dist[y] = d+i;
                src[y] = x;
                edge[y] = i;
                Q.emplace(dist[y], y);
            }
        }
    }
    stack<int> res;
    int x = 0;
    do {
        res.push(edge[x]);
        x = src[x];
    } while (x != 0);

    while (!res.empty()){
        cout << res.top();
        res.pop();
    }
    
    return 0;
}
