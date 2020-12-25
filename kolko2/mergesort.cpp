#include<bits/stdc++.h>

using namespace std;

int32_t inv = 0;

vector<int32_t> mergesort(vector<int32_t> base){
    if (base.size() == 1){
        return base;
    }
    int32_t m = base.size()/2;

    vector<int32_t> lo(base.begin(), base.begin() + m);
    lo = mergesort(lo);
    
    vector<int32_t> hi(base.begin() + m, base.end());
    hi = mergesort(hi);

    vector<int32_t> result;
    uint32_t i = 0, j = 0; 

    while (i < lo.size() and j < hi.size()){
        if (lo[i]<=hi[j]){
            result.push_back(lo[i]);
            i++;
        }
        else {
            result.push_back(hi[j]);
            j++;
            inv+=lo.size() - i;
        }
    }
    while (i < lo.size()){
        result.push_back(lo[i]);
        i++;
    }
    while (j < hi.size()){
        result.push_back(hi[j]);
        j++;
    }
    return result;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    uint32_t n;
    cin >> n;
    vector<int32_t> V;
    for (uint32_t i = 0; i < n; i++){
        int32_t a;
        cin >> a;
        V.push_back(a);
    }
    mergesort(V);
    /*for (auto c : result){
        cout << c << " ";
    }*/
    cout << inv;

	return 0;
}