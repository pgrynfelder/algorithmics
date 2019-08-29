#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+7, LOG_N = 21;
unordered_map<string, int> dict;
int n;
int dist[N];
int jumpptr[N][LOG_N];

void init(string nazwa){
    dict[nazwa] = ++n;
    for (int i = 0; i < LOG_N; i++){
        jumpptr[1][i] = 1;
    }
}

void nowa_osada(string nowa, string stara, int dlugosc){
    dict[nowa] = ++n;
    int parent = dict[stara];
    int current = dict[nowa];
    dist[current] = dist[parent] + dlugosc;

    jumpptr[current][0] = parent;
    for (int i = 1; i < LOG_N; i++)
    {
        jumpptr[current][i] = jumpptr[jumpptr[current][i-1]][i-1];
    }
}

int lca(int a, int b){
    if (dist[a] > dist[b]){
        swap(a,b);
    }
    for (int i = LOG_N-1; i >= 0; i--){
        if (dist[jumpptr[b][i]] >= dist[a]){
            b = jumpptr[b][i];
        }
    }
    if (a==b) return a;
    
    for (int i = LOG_N-1; i >= 0; i--){
        if (jumpptr[a][i] != jumpptr[b][i]){
            a = jumpptr[a][i];
            b = jumpptr[b][i];
        }
    }
    return jumpptr[a][0];
}

int odleglosc(string pierwsza, string druga){
    int a = dict[pierwsza], b = dict[druga];
    int xd = lca(a, b);
    return dist[a] + dist[b] - 2*dist[xd];
}

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     init("RABARBARUM");
//     nowa_osada("AKWARIUM", "RABARBARUM", 3);
//     cout << odleglosc("AKWARIUM", "RABARBARUM") << '\n';
//     nowa_osada("RELANIUM", "RABARBARUM", 2);
//     nowa_osada("GALIUM", "RELANIUM", 1);
//     nowa_osada("DELIRIUM", "RELANIUM", 4);
//     cout << odleglosc("AKWARIUM", "DELIRIUM") << '\n';
//     cout << odleglosc("AKWARIUM", "GALIUM") << '\n';
//     return 0;
// }
