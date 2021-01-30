#include <bits/stdc++.h>
using namespace std;

struct v2d {
    int x = 0, y = 0;
    v2d(int _x = 0, int _y = 0) { x = _x, y = _y; }
    int operator^(v2d &other) { // cross product
        return x * other.y - y * other.x;
    }
    v2d operator+(v2d &other) { return v2d(x + other.x, y + other.y); }
    v2d operator-(v2d &other) { return v2d(x - other.x, y - other.y); }
    int operator*(v2d &other) { // dot product = a * b * sin
        return x * other.x + y * other.y;
    }
    int operator^(v2d &other) { // cross product = a * b * cos
        return x * other.y - other.x * y;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
