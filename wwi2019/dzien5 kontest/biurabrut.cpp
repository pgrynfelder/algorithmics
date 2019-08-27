#include<bits/stdc++.h>
using namespace std;

vector<int> comp;
vector<int> comp_count;
set<pair<int, int>> used;
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    comp.resize(n+1);
    comp_count.resize(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if (a > b){
            swap(a, b);
        }
        used.emplace(a, b);
    }
    int i = 1;
    for (int v = 1; v <= n; v++){
        if (comp[v] == 0){
            stack<int> s;
            comp[v] = i;
            comp_count[comp[v]]++;
            s.push(v);
            while (!s.empty()){
                int a = s.top();
                s.pop();
                for (int b = 1; b <= n; b++){
                    if (a != b and comp[b] == 0 and !used.count({min(a, b), max(a, b)})){
                        comp[b] = comp[a];
                        comp_count[comp[b]]++;
                        s.push(b);
                    }
                }
            }
            i++;
        }
    }
    cout << i - 1 << '\n';
    sort(comp_count.begin(), comp_count.end());
    for (int &a : comp_count){
        if (a != 0){
            cout << a << ' ';
        }
    }
    return 0;
}
