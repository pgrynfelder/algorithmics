#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7;
vector<int> graph[MAXN];
bool vis[MAXN];
int k, siz[MAXN], cnt[MAXN][2], root;
long long res = 0;

void dfs(const int &u, const int &p) {
        siz[u] = 1;
            for(int &v : graph[u]) {
                        if(v != p && !vis[v]) {
                                        dfs(v, u);
                                                    siz[u] += siz[v];
                                                            }
                            }
}

void dfs1(const int &u, const int &p, const int &d) {
        if(d > k) {
                    return;
                        }
            if(cnt[k - d][1] == root) {
                        res += cnt[k - d][0];
                            }
                for(int &v : graph[u]) {
                            if(v != p && !vis[v]) {
                                            dfs1(v, u, d + 1);
                                                    }
                                }
}

void dfs2(const int &u, const int &p, const int &d) {
        if(d > k) {
                    return;
                        }
            if(cnt[d][1] != root) {
                        cnt[d][0] = 1;
                                cnt[d][1] = root;
                                    }
                else {
                            ++cnt[d][0];
                                }
                    for(int &v : graph[u]) {
                                if(v != p && !vis[v]) {
                                                dfs2(v, u, d + 1);
                                                        }
                                    }
}

void centroid_decomposition(const int &u) {
        dfs(u, 0);
            int centroid = u, p = 0;
                bool ok = 0;
                    while(!ok) {
                                ok = 1;
                                        for(int &v : graph[centroid]) {
                                                        if(v != p && !vis[v] && (siz[v] << 1) > siz[u]) {
                                                                            p = centroid;
                                                                                            centroid = v;
                                                                                                            ok = 0;
                                                                                                                            break;
                                                                                                                                        }
                                                                }
                                            }
                        cnt[0][0] = 1;
                            cnt[0][1] = root = centroid;
                                for(int &v : graph[centroid]) {
                                            if(!vis[v]) {
                                                            dfs1(v, centroid, 1);
                                                                        dfs2(v, centroid, 1);
                                                                                }
                                                }
                                    vis[centroid] = 1;
                                        for(int &v : graph[centroid]) {
                                                    if(!vis[v]) {
                                                                    centroid_decomposition(v);
                                                                            }
                                                        }
}

int main() {
        ios_base::sync_with_stdio(0);
            cin.tie(0);
                cout.tie(0);
                    
                    int n, u, v;
                        cin >> n >> k;
                            for(int i = 2; i <= n; ++i) {
                                        cin >> u >> v;
                                                graph[u].push_back(v);
                                                        graph[v].push_back(u);
                                                            }
                                centroid_decomposition(1);
                                    cout << res;
                                        
                                        return 0;
}
