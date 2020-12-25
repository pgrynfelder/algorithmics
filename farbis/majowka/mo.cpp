/*
przechodzimy między przedziałami gąsienicą
koszt przejścia [a,b] -> [c,d]: |a-c| + |c-d|
czyli chcemy posortować tak zapytania,
by zminimalizować łamaną po prostokątnych po wszystkich punktach

cmp - przyzwoita heura na to

#mo
#gasienica
*/
#include<bits/stdc++.h>
using namespace std;


constexpr int N = 1e5 + 7, MAX = 1e6 + 7;
int n, SQ, l[N], r[N], q, t[N], cnt[MAX];
unsigned long long current;
unsigned long long res[N];

void add(long long x){
    current += x * (2*cnt[x] + 1);
    cnt[x]++;
}

void sub(long long x){
    current -= x * (2*cnt[x] - 1);
    cnt[x]--;
}

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
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
    vector<int> Q;
    for (int i = 1; i <= q; i++){
        cin >> l[i] >> r[i];
        Q.push_back(i);
    }
    sort(Q.begin(), Q.end(), cmp);
    int a = 1, b = 0;
    for (int i : Q){
        while (a != l[i] or b != r[i]){
            if (a < b + 1){ // may a++ or b--
                if (a < l[i]){
                    sub(t[a]);
                    a++;
                }
                else if (b > r[i]){
                    sub(t[b]);
                    b--;
                }
            }
            if (a > l[i]){
                a--;
                add(t[a]);
            }
            else if (b < r[i]){
                b++;
                add(t[b]);
            }
        }
        res[i] = current;
    }
    for (int i = 1; i <= q; i++){
        cout << res[i] << "\n";
    }
    return 0;
}

/*

8 3
4 3 1 1 1 3 1 2
2 7
1 6
3 8

res:
28
25
21

*/