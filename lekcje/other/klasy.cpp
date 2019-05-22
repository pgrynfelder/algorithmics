#include<bits/stdc++.h>
using namespace std;

int n;

int xd(int x, int y){
    int m, x0, y0, k;

    m = max(abs(((double)(n-1))/2 - x), abs(((double)(n-1))/2 - y)) * 2 + 1;
    k = (n-m)*(n+m)+1;
    x0 = y0 = (n - m)/2;
    
    if (x == x0){
        k += y - y0;
    }
    else if (y == y0){
        k += 4*(m-1);
        k -= x - x0;
    }
    else if (y == y0 + m - 1){
        k += y - y0 + x - x0;
    }
    else {
        k += 2*(m-1);
        k += y0 + m - 1 - y;
    }
    return k;
}

pair<int, int> rotate(pair<int, int> xy){ // rotates 90 deg ccw
    int x0 = (xy.second - ((double)(n-1))/2)*(-1) + ((double)(n-1))/2;
    int y0 = (xy.first - ((double)(n-1))/2) + ((double)(n-1))/2;
    return {x0, y0};
}

int symmetry(int c){
    return n-1 - c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, x2, y1, y2;
    string dir, curve;
    cin >> n >> dir >> curve;
    cin >> x1 >> x2 >> y1 >> y2;
    x1--; x2--; y1--; y2--;
    // for x,y
    // cout << xd(x, y); // default is NORTH RIGHT

    int x = x1, y = y2;
    while (y >= y1){
        x = x1;
        while (x <= x2){
            // ROTATION
            pair<int, int> xy = {x,y};
            if (dir == "WSCHOD"){
                xy = rotate(xy);
            }
            else if (dir == "POLUDNIE"){
                xy = rotate(rotate(xy));
            }
            else if (dir == "ZACHOD"){
                xy = rotate(rotate(rotate(xy)));
            }
            int x0 = xy.first, y0 = xy.second;

            if (curve == "LEWO"){
                x0 = symmetry(x0);
            }
            cout << xd(x0, y0) << ' ';
            x++;
        }
        cout << '\n';
        y--;
    }
    
}
