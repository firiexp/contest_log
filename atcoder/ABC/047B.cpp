#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int w, h, n, x, y, a;
    cin >> w >> h >> n;
    int xp = w, xm = 0, yp = h , ym = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> a;
        if (a == 1) xm = max(xm,x);
        else if (a == 2) xp = min(xp,x);
        else if (a == 3) ym = max(ym,y);
        else if (a == 4) yp = min(yp,y);
    }
    cout << ((xp > xm) && (yp > ym) ? (xp-xm)*(yp-ym) : 0 ) << "\n";
    return 0;
}