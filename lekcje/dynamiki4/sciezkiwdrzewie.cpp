#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+7;
int n, k;
long long result;

struct Counter {
    int c = 0;
    unordered_map<int, int> values;
    void add(int i, int x){
        values[i - c]+=x;
    }
    int get(int i){
       return values[i - c];
    }
    size_t size(){ return values.size(); }
};

Counter *counter[N];

vector<int> G[N];

void dfs(int v, int p){
    Counter *biggust = 0;
    for (int u : G[v]){
        if (u != p){
            dfs(u, v);
            if (!biggust or counter[u]->size() > biggust->size()){
                biggust = counter[u];
            }
        }
    }
    counter[v] = biggust;
    if (!counter[v]){
        counter[v] = new Counter();
    }
    counter[v]->c++;
    for (int u : G[v]){
        if (u != p and counter[v] != counter[u]){
            for (auto x : counter[u]->values){
                int len = x.first + counter[u]->c;
                if (len < k - 1){
                    result += x.second * counter[v]->get(k - len);
                }
                counter[v]->add(len, x.second);
            }
        }
    }
    counter[v] -> add(1, 1);
    result += counter[v]->get(k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    k++; // we'll be operating on the number of edges
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(1, 0);

    cout << result << "\n";


    return 0;
}
