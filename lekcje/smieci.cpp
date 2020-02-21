#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 7, M = 1e6 + 7;

vector<pair<int, int>> G[N];
bool deg[N];
bool occ[N];
int n, m;

int visitedV[N];
bool visitedE[M];

vector<int> res;
void euler(int v){
    for (auto e : G[v]){
        if (!visitedE[e.second]){
            visitedE[e.second] = 1;
            visitedV[e.first] = 1;
            euler(e.first);
        }
    }
    res.push_back(v);
    // cout << v << " ";
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
            deg[a] ^= 1; deg[b] ^= 1;
            G[a].emplace_back(b, i);
            G[b].emplace_back(a, i);
        }
    }
    for (int i = 1; i <= n; i++){
        if (deg[i]){
            cout << "NIE\n"; return 0;
        }
    }
    vector<stack<int>> XD;
    for (int i = 1; i <= n; i++){
        if (!visitedV[i]){
            visitedV[i] = 1;
            euler(i);
            // res.pop();
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
            res.clear();
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