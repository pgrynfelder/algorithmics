#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef tuple<ll,ll,ll,ll> vertex;

vector<ll> questions;
unordered_map<ll, ll> whereis;

class Compare {
public:
bool operator() (vertex a, vertex b){
    return get<3>(a) > get<3>(b);
}
};

int n, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    
    questions.resize(n);
    for (int i = 0; i<n; i++){
        cin >> questions[i];
    }
    sort(questions.begin(), questions.end());
    for (int i = 0; i < questions.size(); i++){
        whereis[questions[i]] = i;
    }
    questions.push_back(0);
    
    priority_queue<vertex, vector<vertex>, Compare> q;
    
    set<vertex> visited;
    ll result = 0;
    q.push(vertex(questions[0], questions[0], questions[0], questions[0]*3));
    while (!q.empty()){
        vertex v = q.top();
        ll a, b, c, dist;
        tie(a, b, c, dist) = v;
        q.pop();
        if (visited.count(v) != 0) continue;
        visited.insert(v);
        k--;
        if (k==0){
            result = dist;
            break;
        }
        vertex u = vertex(questions[whereis[a]+1], b, c, questions[whereis[a]+1]+b+c);
        if (visited.count(u) == 0 and whereis[a]+1 < questions.size()) q.push(u);
        
        u = vertex(a, questions[whereis[b]+1], c, questions[whereis[b]+1]+a+c);
        if (visited.count(u) == 0 and whereis[b]+1 < questions.size()) q.push(u);
        
        u = vertex(a, b, questions[whereis[c]+1], questions[whereis[c]+1]+b+a);
        if (visited.count(u) == 0 and whereis[c]+1 < questions.size()) q.push(u);
    
    }
    cout << result << '\n';
    
    return 0;
}
/*
4 5
1 2 5 4
*/