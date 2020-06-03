#include<bits/stdc++.h>
using namespace std;

/*
przechodzimy między przedziałami gąsienicą
koszt przejścia [a,b] -> [c,d]: |a-c| + |c-d|
czyli chcemy posortować tak zapytania,
by zminimalizować łamaną po prostokątnych po wszystkich punktach

cmp - przyzwoita heura na to
*/
constexpr int N = 1e5 + 7;
int n, SQ, l[N], r[N], q;

bool cmp(const int a, const int b) 
{
		int x = l[a] / SQ, y = l[b] / SQ;
		return make_pair(x, x%2 ? r[a] : -r[a]) < make_pair(y, y%2 ? r[b] : -r[b]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    SQ = sqrt(q);
    cout << SQ;
    return 0;
}
