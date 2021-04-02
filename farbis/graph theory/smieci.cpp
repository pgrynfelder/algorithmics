#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, M = 1e6 + 7;

vector<pair<int, int>> G[N];
int deg[N];
bool occ[N];
int n, m;

int visitedV[N];
int last[N];
bool visitedE[M];

void euler(int v, vector<int> &res){
    for ( ; last[v] < G[v].size(); last[v]++ ){
        auto &e = G[v][last[v]];
        if (!visitedE[e.second]){
            visitedE[e.second] = 1;
            visitedV[e.first] = 1;
            euler(e.first, res);
        }
    }
    res.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c ^ d){
            deg[a]++; deg[b]++;
            G[a].emplace_back(b, i);
            G[b].emplace_back(a, i);
        }
    }
    for (int i = 1; i <= n; i++){
        if (deg[i] & 1){
            cout << "NIE\n"; return 0;
        }
    }
    vector<stack<int>> XD;
    for (int i = 1; i <= n; i++){
        if (!visitedV[i] and deg[i] > 0){
            visitedV[i] = 1;
            vector<int> res;
            euler(i, res);
            stack<int> rEzUlTaT;
            for (int v : res){
                if (occ[v]){
                    XD.emplace_back();

                    XD.rbegin() -> push(v);

                    while(rEzUlTaT.top() != v){
                        occ[rEzUlTaT.top()] ^= 1;
                        XD.rbegin() -> push(rEzUlTaT.top());
                        rEzUlTaT.pop();
                    }
                    occ[v] ^= 1;
                    XD.rbegin() -> push(v);
                    rEzUlTaT.pop();
                }
                occ[v] ^= 1;
                rEzUlTaT.push(v);
            }
        }
    }
    cout << XD.size() << "\n";
    for (auto &s : XD){
        cout << s.size() - 1 << " ";
        while (!s.empty()){
            cout << s.top() << " "; s.pop();
        }
        cout << "\n";
    }
    return 0;
}