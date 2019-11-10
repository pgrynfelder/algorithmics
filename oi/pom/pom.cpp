#include<bits/stdc++.h>
using namespace std;


constexpr int N = 1e5 + 7;

struct range {
    int l, r;
    range(int _l, int _r){
        l = _l; r = _r;
    }
    bool empty(){
        return l > r;
    }
    bool find(int x){
        return (l <= x and x <= r);
    }
    range operator+ (int x){
        return range(l + x, r + x);
    }
    range operator| (range other){ // they're always intersecting or almost instersecting
        if (other.empty()){
            return *this;
        }
        else if (this->empty()){
            return other;
        }
        else {
            return range(min(l, other.l), max(r, other.r));
        }
    }
};

int equalised[N];
string A, B, C;
int t, n, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t-->0){
        cin >> A >> B >> k;
        n = A.size();
        for (int i = 0; i < n; i++){
            equalised[i+1] = equalised[i];
            if (A[i] != B[i]) equalised[i+1]++;
        }
        range previous = range(1, 0);
        range current = previous;
        int found = -1;
        for (int i = n - 1; i >= 0; i--){
            if (A[i] < B[i]){
                if (B[i] == '1'){ // we leave a unchanged or we change it to b
                    current = range(0, n - i - 1) | (previous + 1); // so we can change every next
                }
                else { // we can change a or leave it unchanged
                    current = range(0, n - i);
                }
            }
            if (A[i] == B[i]){
                if (A[i] == '0'){ // a cannot be lowered so we leave it unchanged
                    current = previous; // so we can only rely on previous settings
                }
                else { // a can be lowered
                    current = previous | range(1, n - i); // so we can leave it or change it and all next
                }
            }
            if (A[i] > B[i]){
                if (B[i] == '0'){ // we can only change a to equal b
                    current = previous + 1; // so we have previous enlargened by change of a
                }
                else { // we can change a to lower than b (or equal but it doesnt matter since previous + 1 is always within range)
                    current = range(1, n - i);
                }
            }
            // cout << current.l << " " << current.r << "\n";
            if (current.find(k - equalised[i])){
                found = i;
                break;
            }
            previous = current;
        }
        // for (int i = 0; i <= n; i++){
        //     cout << equalised[i] << " ";
        // }
        cout << "found: " << found << "\n";
        if (found == -1){
            cout << "-1\n";
            continue;
        }
        C = A;
        int j = k;
        for (int i = 0; i < found; i++){
            C[i] = B[i]; 
            if (A[i] != B[i]){
                j--;
            }
        }
        // cout << "j: " << j << "\n"; 
        if (j == 0){
            // do nothing
        }
        else {
            C[found] = B[found] - 1;
        }
        if (C[found] != A[found]) j--;

        for (int i = found + 1; i < n and j > 0; i++){
            if (A[i] != '9'){
                C[i] = '9'; j--;
            }
        }
        for (int i = n - 1; j > 0; i--){ // coś tutaj nie działa
            if (A[i] == '9'){
                C[i] = '8'; j--;
            }
        }
        // for (int i = 0; i < n; i++){
        //     if (C[i] != B[i]){
        //         cout << i << "\n";
        //         // break;
        //     }
        // }
        // cout << C << "\n";
    }
    return 0;
}

// gotta prepare separate cases: when keeping a and when changing