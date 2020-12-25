#include <bits/stdc++.h>
using namespace std;

struct v2d {
    int x = 0, y = 0;
    v2d(int _x, int _y) { x = _x, y = _y; }
    v2d(){};
    int operator^(v2d &other) { // cross product
        return x * other.y - y * other.x;
    }
    v2d operator+(v2d &other) { return v2d(x + other.x, y + other.y); }
    v2d operator-(v2d &other) { return v2d(x - other.x, y - other.y); }
    int operator*(v2d &other) { // dot product
        return x * other.x + y * other.y;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}

// cross product
// A x B = xa * yb - ya * xb = a * b * sin
//
// dot produtto
// A * B = xa * xb + ya * yb = a * b * cos
