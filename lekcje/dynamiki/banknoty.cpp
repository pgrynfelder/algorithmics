#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = 1e6+7;

struct Note {
    ll v = 0, n = 0, i = 0;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n;
    
    vector<Note> notes(n);
    for (ll i = 0; i < n; i++){
        cin >> notes[i].v;
    }
    for (ll i = 0; i < n; i++){
        cin >> notes[i].n;
    }
    for (ll i = 0; i < n; i++){
        notes[i].i = i;
    }
    cin >> k;
    
    vector<ll> a(k+1, inf);
    vector<vector<ll>> c(k+1, vector<ll>(n));
    a[0] = 0;
    sort(notes.begin(), notes.end(),[&](Note a, Note b) { return a.v > b.v; });
    for (Note note : notes) {
        for (ll i = 0; i < note.n; i++){
            bool changed = false;
            for (ll j = k; j >= note.v; j--){
                if (a[j - note.v] + 1 < a[j]){
                    changed = true;
                    a[j] = a[j - note.v] + 1;
                    c[j] = c[j - note.v];
                    c[j][note.i]++;
                }
            }
            if (!changed) break;
        }
    }

    cout << a[k] << '\n';
    for (int i : c[k]){
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}