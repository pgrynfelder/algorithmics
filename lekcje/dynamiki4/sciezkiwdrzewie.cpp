#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int n, k;
long long result;

struct Counter {
    int c = 0;
    unordered_map<int, int> values;
    void add(int i, int x){
        values[i - c] += x;
    }
    int get(int i){
        if (values.count(i-c))
            return values[i - c];
        return 0;
    }
    size_t size(){ return values.size(); }
    void print(){
        for (auto x : values){
            cout << x.first + c << ": " << x.second << "\n";
        }
    }
};

Counter *counter[N];
vector<int> G[N];

void dfs(int v, int p){
    Counter *biggest = 0;
    for (int u : G[v]){
        if (u != p){
            dfs(u, v);
            if (!biggest or counter[u]->size() > biggest->size()){
                biggest = counter[u];
            }
        }
    }
    counter[v] = biggest;
    if (!counter[v]){
        counter[v] = new Counter();
        // cout << v << " created new counter\n";
    }
    counter[v]->c++;
    for (int u : G[v]){
        if (u != p){
            if (counter[v] == counter[u]){
                // cout << v << " took counter from " << u << "\n";
            }
            else {
                for (auto x : counter[u]->values){
                    int len = x.first + counter[u]->c;
                    if (len < k - 1){
                        // cout << "added paths going through root +" << x.second * counter[v]->get(k - len) << "\n";
                        result += x.second * counter[v]->get(k - len);
                    }
                    counter[v]->add(len+1, x.second);
                }
            }         
        }
    }
    counter[v] -> add(1, 1);
    // counter[v] -> print();

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
