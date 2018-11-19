#include<bits/stdc++.h>

using namespace std;

struct Heap {
    int32_t h[1000000] = {INT32_MAX};
    int32_t size = 1;
    void add(int32_t a){
        h[size] = a;
        int32_t i = size;
        size++;
        while (h[i/2] < h[i]){
            int32_t a = h[i];
            h[i] = h[i/2];
            h[i/2] = a;
            i /= 2;
        }
    }

    int32_t pop(){
        int32_t result = h[1];
        h[1] = h[size];
        int32_t i = 1;
        size--;

        bool heapify = true;
        while (heapify and i <= size){
            heapify = false;
            if (h[i*2] >= h[i*2+1] and h[i*2] > h[i]){
                heapify = true;
                int32_t a = h[i];
                h[i] = h[i*2];
                h[i*2] = a;
                i *= 2;
            }
            else if (h[i*2] < h[i*2+1] and h[i*2+1] > h[i]){
                heapify = true;
                int32_t a = h[i];
                h[i] = h[i*2+1];
                h[i*2+1] = a;
                i = 2*i + 1;
            }
        }

        return result;
    }

    bool empty(){
        return size < 2;
    }

    void print(){
        for (int32_t i = 1; i < size; i *= 2){
            for (int32_t j = i; j < i*2; j++){
                cout << h[j] << ' ';
            }
            cout << '\n';
        }
    }
};

Heap h;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int32_t a, n;
    cin >> n;
    for (int32_t i = 0; i < n; i++){
        cin >> a;
        h.add(a);
    }
    while(!h.empty()){
        cout << h.pop() << ' ';
    }
    return 0;
}