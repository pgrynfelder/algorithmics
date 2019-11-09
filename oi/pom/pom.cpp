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
        return (l <= x and x < r);
    }
    range operator+ (int x){
        return range(l + x, r + x);
    }
    range operator+ (range other){ // they're always intersecting or almost instersecting
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
string A;
string B;
int t;
int n;
int k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t-->0){
        cin >> A >> B >> k;
        n = A.size();
        for (int i = 0; i < n; i++){
            equalised[i+1] = equalised[i];
            if (A[i] != B[i]) equalised[i + 1]++;
        }
        range current = range(1, 0);
        int found = -1;
        for (int i = n - 1; i >= 0; i--){
            if (A[i] < B[i]){
                if (B[i] > '1'){
                    current = range(0, n - i) + (current + 1);
                }
                else {
                    current = range(0, n - i - 1) + (current + 1);
                }
            }
            if (A[i] == B[i]){
                if (A[i] == '0'){
                    current = current;
                }
                else {
                    current = current + range(1, n - i);
                }
            }
            if (A[i] > B[i]){
                if (B[i] == '0'){
                    current = current + 1;
                }
                else {
                    current = range(1, n - i);
                }
            }
            // cout << current.l << " " << current.r << "\n";
            if (current.find(k - equalised[i])){
                found = i;
                break;
            }
        }
        cout << found << "\n";
    }
    return 0;
}