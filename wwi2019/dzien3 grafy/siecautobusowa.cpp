#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge {
    int w, d, t, o;
    edge (int _w, int _d, int _t, int _o){
        w = _w; d = _d; t = _t; o = _o;
    }
};

#ifdef _WIN32
inline int getchar_unlocked() {
return getchar();
}
#endif
template <typename T> T getczary(){//magia!
  int ujemna = false, znak = getchar_unlocked();
  T wynik = (T)0;
  while(!isdigit(znak)){
    if(znak == '-')
      ujemna = true;
    znak = getchar_unlocked();
  }
  while(isdigit(znak)){
    wynik *= 10;
    wynik += znak - '0';
    znak = getchar_unlocked();
  }
  if(ujemna)
    wynik *= -1;
  return wynik;
}

vector<vector<edge>> G;
vector<ll> distances;
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    n = getczary<int>();
    G.resize(n+1);
    distances.resize(n+1);
    for (int i=1; i <= n; i++){
        int m;
        m = getczary<int>();
        while (m-->0)
        {
            int w, d, t, o;
            w = getczary<int>(); d = getczary<int>(); t = getczary<int>(); o = getczary<int>();
            //cin >> w >> d >> t >> o;
            G[i].push_back({w, d, t, o});
        }
        
        distances[i] = LONG_LONG_MAX;
    }

    distances[1] = 0;
    priority_queue<pair<ll,int>> q;
    q.push({-0,1});
    while (!q.empty()){
        ll t = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (t > distances[v]) continue;
        for (edge &e : G[v]){
            ll mod = ((ll)e.t-t)%e.o;
            if (mod < 0) mod += e.o;
            if (mod+e.d+t < distances[e.w]){
              q.push({-(mod+e.d+t), e.w});
              distances[e.w] = mod+e.d+t;
            }
        }
    }
    if (distances[n] == LONG_LONG_MAX){
        cout <<"ARESZT\n";
    }
    else {
        cout << distances[n] << '\n';
    }

    return 0;
}
/*
5
2
4 10 0 7
3 1 1 7
0
1
2 7 12 55
2
5 3 3 10
5 2 1 100
0
*/