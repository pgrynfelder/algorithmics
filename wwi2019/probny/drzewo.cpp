#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7, p = 1e6 + 7;

vector<int> nbh[maxN];
int N;


long long dfs_hsh(int v, int parent) {
    long long hsh = v;
    for (int a : nbh[v])
        if (a != parent)
            hsh = (hsh * p + dfs_hsh(a, v)) % mod;
    return hsh;
}


bool create_bug() {
    if (N < 1e4)
        return false;

    long long hsh = dfs_hsh(N, -1);
    return hsh % 312 == 13;
}


int main() {
    scanf("%d", &N);
    for (int a, b, i = 1; i < N; ++i) {
        scanf("%d%d", &a, &b);
        nbh[a].push_back(b);
        nbh[b].push_back(a);
    }

    if (create_bug())
        printf("No żeż bug.");
    else
        printf("Działa dobrze.");
}
