#include <bits/stdc++.h>
using namespace std;

struct vec {
    long long x, y;
    vec(int _x = 0, int _y = 0) { x = _x, y = _y; }
};
vec operator+(const vec &a, const vec &b) { return vec(a.x + b.x, a.y + b.y); }
vec operator-(const vec &a) { return vec(-a.x, -a.y); }
vec operator-(const vec &a, const vec &b) { return a + (-b); }
long long operator^(const vec &a, const vec &b) {
    return a.x * b.y - b.x * a.y;
}

vector<vec> convex_hull(vector<vec> points) {
    if (points.size() <= 3) return points;

    vector<vec> lo, up, res;

    sort(points.begin(), points.end(), [](const vec &a, const vec &b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });

    for (vec &a : points) {
        while (up.size() >= 2 and ((up[up.size() - 1] - up[up.size() - 2]) ^
                                   (a - up[up.size() - 2])) < 0)
            up.pop_back();
        up.push_back(a);
    }
    reverse(points.begin(), points.end());
    for (vec &a : points) {
        while (lo.size() >= 2 and ((lo[lo.size() - 1] - lo[lo.size() - 2] ^
                                    (a - lo[lo.size() - 2])) < 0))
            lo.pop_back();
        lo.push_back(a);
    }
    for (int i = 0; i < up.size() - 1; i++) res.push_back(up[i]);
    for (int i = 0; i < lo.size() - 1; i++) res.push_back(lo[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<vec> points;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    auto hull = convex_hull(points);
    int h = hull.size();
    int in = n - h;
    cout << 2 * n - h - 3;
    return 0;
}