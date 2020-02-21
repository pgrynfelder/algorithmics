/* Wawszczak, macierz, bitset */
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 107;

struct matrix {
	int h, w;
	bitset<N> m[N];
	
	matrix();
	
	matrix(int _h, int _w) {
		h = _h, w = _w;
		
		for(int i = 0; i < w; ++i) {
			m[i] = 0;
		}
	}
	
	matrix operator* (matrix &other) {
		matrix res(h, other.w);
		
		for(int i = 0; i < res.h; ++i) {
			bitset<N> cur = 0;
			for(int j = 0; j < w; ++j) {
				if(m[j][i]) {
					cur[j] = 1;
				}
			}
			
			for(int j = 0; j < res.w; ++j) {
				if(!(cur & other.m[j]).none()) {
					res.m[j][i] = 1;
				}
			}
		}
		
		return res;
	}
};

// for N <= 32
struct matrix {
	int h, w;
	int a[N];
	
	matrix() {
		h = w = 0;
	}
	
	matrix(int _h, int _w) {
		h = _h, w = _w;
		
		for(int i = 0; i < h; ++i) {
			a[i] = 0;
		}
	}
	
	matrix operator *(matrix other) {
		matrix res(h, other.w);
		
		for(int j = 0; j < res.w; ++j) {
			int cur = 0;
			for(int i = 0; i < other.h; ++i) {
				if(other.a[i] >> j & 1) {
					cur |= 1 << i;
				}
			}
			
			for(int i = 0; i < res.h; ++i) {
				if(a[i] & cur) {
					res.a[i] |= 1 << j;
				}
			}
		}
		
		return res;
	}
};