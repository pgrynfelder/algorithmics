#include<bits/stdc++.h>

using namespace std;

struct MaxHeap {
    pair<int32_t, int32_t> h[1050000];
    h[0].first = INT_MAX;
    h[0].second = INT_MAX;
    int32_t size = 1;
    void add(pair<int32_t, int32_t> a){
        h[size] = a;
        int32_t i = size;
        size++;
        while (h[i/2].first < h[i].first){
            pair<int32_t, int32_t> a = h[i];
            h[i] = h[i/2];
            h[i/2] = a;
            i /= 2;
        }
    }

    void pop(){
        h[1] = h[size];
        h[size] = {0, 0};
        int32_t i = 1;
        size--;
        bool heapify = true;
        while (heapify){
            heapify = false;
            if (i*2 <= size and h[i*2].first >= h[i*2+1].first and h[i*2].first > h[i].first){
                heapify = true;
                pair<int32_t, int32_t> a = h[i];
                h[i] = h[i*2];
                h[i*2] = a;
                i *= 2;
            }
            else if (i*2+1 <= size and h[i*2].first < h[i*2+1].first and h[i*2+1].first > h[i].first){
                heapify = true;
                pair<int32_t, int32_t> a = h[i];
                h[i] = h[i*2+1];
                h[i*2+1] = a;
                i = 2*i + 1;
            }
        }
        return;
    }

    pair<int32_t, int32_t> top(){
        return h[1];
    }

    bool empty(){
        return size < 2;
    }
};

MaxHeap heap;
pair<int32_t, int32_t> v[1050000];

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
    
    int32_t i = n;
    while(!heap.empty()){
        i--;
        v[i] = heap.top();
        heap.pop();
    }
    
    i = 0;
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

