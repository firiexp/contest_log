#include <iostream>
#include <cmath>

using ll = long long;
using namespace std;

/* initialize */
int n;
struct point {double x, y;};
/* main */
void koch(int d, point p1, point p2){
    if (d == 0) return;
    point s{0,0}, t{0,0}, u{0,0};
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x -s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x -s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(d-1,p1 ,s);
    printf("%.8f  %.8f\n", s.x, s.y);
    koch(d-1,s ,u);
    printf("%.8f  %.8f\n", u.x, u.y);
    koch(d-1,u,t);
    printf("%.8f  %.8f\n", t.x, t.y);
    koch(d-1,t,p2);
}
int main() {
    cin >> n;
    point s1{0, 0};
    point s2{100, 0};
    printf("%.8f  %.8f\n", s1.x, s1.y);
    koch(n,s1,s2);
    printf("%.8f  %.8f\n", s2.x, s2.y);
    return 0;
}