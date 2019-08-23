#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef tuple<ll,ll,ll,ll> vertex;

vector<int> questions;
vector<ll> difficulty;
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
    difficulty.resize(n);
    for (int i = 0; i<n; i++){
        cin >> difficulty[i];
        questions[i] = i;
    }
    sort(questions.begin(), questions.end(), [&](const int a, const int b){return difficulty[a] < difficulty[b];});
    for (int i = 0; i < questions.size(); i++){
        whereis[questions[i]] = i;
    }
    
    
    priority_queue<vertex, vector<vertex>, Compare> q;
    
    set<vertex> visited;
    ll result = 0;
    q.push(vertex(questions[0], questions[0], questions[0], difficulty[questions[0]]*3));
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
        vertex u;

        if (whereis[a]+1 < questions.size()){
            u = vertex(questions[whereis[a]+1], b, c,
            difficulty[questions[whereis[a]+1]] + difficulty[b] + difficulty[c]);
            if (visited.count(u) == 0) q.push(u);
        }
        if (whereis[b]+1 < questions.size()){
            u = vertex(a, questions[whereis[b]+1], c, 
            difficulty[questions[whereis[b]+1]] + difficulty[c] + difficulty[a]);
            if (visited.count(u) == 0) q.push(u);
        }
        if (whereis[c]+1 < questions.size()){
            u = vertex(a, b, questions[whereis[c]+1],
            difficulty[questions[whereis[c]+1]] + difficulty[a] + difficulty[b]);
            if (visited.count(u) == 0) q.push(u);
        }
    
    }
    cout << result << '\n';
    
    return 0;
}
/*
4 5
1 2 5 4
*/