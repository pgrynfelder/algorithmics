#include<bits/stdc++.h>
using namespace std;


constexpr int N = 1e5 + 7;

struct range {
    int l, r;
    bool find(int x){
        return (l <= x and x <= r);
    }
    void translate(int x){
        l += x; r += x;
    }
};

struct xd {
    bool t[11*N/10];
    int change = N;
    bool find(int x){
        return t[x + change];
    } 
    void translate(int x){
        change -= x;
    }
    void push(int x){
        t[x + change] = true;
    }
};
// maybe will rewrite to set later