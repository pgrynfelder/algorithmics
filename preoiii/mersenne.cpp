#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

constexpr uint K = 31, N = 1e6+7; 
constexpr ull M = (1 << K) - 1;

ull mod(ull x)
{
    x = (x >> K) + (x & M);
    x = (x >> K) + (x & M);
    return x == M ? 0 : x;
}


