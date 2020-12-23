#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 7;
int n;
int s[N];
bool visited[N];
vector<int> G[N];

bool divide(int v, int k) { // k - number of vertices
    for (int u : G[v]) {
        if (!visited[u]) {
            visited[u] = 1;
            if (divide(u, k) == false)
                return false;
            s[v] += s[u];
        }
    }
    s[v]++;
    if (s[v] > k) {
        return false;
    }
    if (s[v] == k)
        s[v] -= k;
    return true;
}
void clearup() {
    for (int v = 1; v <= n; v++) {
        visited[v] = 0;
        s[v] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> res = {n}; // na ile spójnych dzielimy
    for (int k = 2; k * k <= n; k++) {
        if (n % k == 0) {

            int k2 = n / k;
            visited[1] = 1;
            if (divide(1, k))
                res.push_back(k2);
            clearup();
            if (k2 != k) {
                visited[1] = 1;
                if (divide(1, k2))
                    res.push_back(k);
                clearup();
            }
        }
    }
    sort(res.begin(), res.end());
    for (int c : res) {
        cout << c - 1 << " ";
    }
}