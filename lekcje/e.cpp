#include<bits/stdc++.h>

using namespace std;

struct MaxHeap {
    vector<pair<int32_t, int32_t>> h;
    
    void add(pair<int32_t, int32_t> a){
        int32_t i = h.size();
        h.push_back(a);
        while (h[i/2].first < h[i].first){
            pair<int32_t, int32_t> a = h[i];
            h[i] = h[i/2];
            h[i/2] = a;
            i /= 2;
        }
    }

    MaxHeap(){
        h.push_back({INT32_MAX, INT32_MAX});
    }

    void pop(){
        h[1] = h[h.size()-1];
        h.pop_back();
        int32_t i = 1;
        bool heapify = true;
        while (heapify){
            heapify = false;
            if (i*2 < h.size() and h[i*2].first >= h[i*2+1].first and h[i*2].first > h[i].first){
                heapify = true;
                swap(h[i], h[i*2]);
                i *= 2;
            }
            else if (i*2+1 < h.size() and h[i*2].first < h[i*2+1].first and h[i*2+1].first > h[i].first){
                heapify = true;
                swap(h[i], h[i*2+1]);
                i = 2*i + 1;
            }
        }
        return;
    }

    pair<int32_t, int32_t> top(){
        return h[1];
    }

    bool empty(){
        return h.size() < 2;
    }
};

MaxHeap heap;
vector<pair<int32_t, int32_t>> v;

int main(){
    int64_t result = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int32_t m, n;
    cin >> m >> n;
    for (int32_t i = 0; i < n; i++){
        int32_t v, h;
        cin >> v >> h;
        heap.add({h,v});
    }
    while(!heap.empty()){
        v.push_back(heap.top());
        heap.pop();
    }
    reverse(v.begin(), v.end());
    int32_t i = 0;
    for (int32_t h = 1; h <= m; h++){
        while (i < n and v[i].first <= h){
            heap.add({v[i].second, v[i].first}); // now in another order to sort by values
            i++;
        }
        if (!heap.empty()){
            result += heap.top().first;
            heap.pop();
        }
    }
    cout << result << '\n';
    return 0;
}