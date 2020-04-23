#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <complex>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) {
    return Point(real(p) * d, imag(p) * d);
}

istream &operator>>(istream &is, Point &p) {
    Real a, b;
    is >> a >> b;
    p = Point(a, b);
    return is;
}

ostream &operator<<(ostream &os, Point &p) {
    os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

Point rotate(Real theta, const Point &p) {
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

Real radian_to_degree(Real r) {
    return (r * 180.0 / PI);
}

Real degree_to_radian(Real d) {
    return (d * PI / 180.0);
}

Real get_angle(const Point &a, const Point &b, const Point &c) {
    const Point v(b - a), w(c - b);
    Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
    if(alpha > beta) swap(alpha, beta);
    Real theta = (beta - alpha);
    return min(theta, 2 * acos(-1) - theta);
}

namespace std {
    bool operator<(const Point &a, const Point &b) {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
}


struct Line {
    Point a, b;

    Line() = default;

    Line(Point a, Point b) : a(a), b(b) {}

    Line(Real A, Real B, Real C) // Ax + By = C
    {
        if(eq(A, 0)) a = Point(0, C / B), b = Point(1, C / B);
        else if(eq(B, 0)) b = Point(C / A, 0), b = Point(C / A, 1);
        else a = Point(0, C / B), b = Point(C / A, 0);
    }

    friend ostream &operator<<(ostream &os, Line &p) {
        return os << p.a << " to " << p.b;
    }

    friend istream &operator>>(istream &is, Line &a) {
        return is >> a.a >> a.b;
    }
};

struct Segment : Line {
    Segment() = default;

    Segment(Point a, Point b) : Line(a, b) {}
};

Real cross(const Point &a, const Point &b) {
    return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b) {
    return real(a) * real(b) + imag(a) * imag(b);
}

int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if(cross(b, c) > EPS) return +1;  // "COUNTER_CLOCKWISE"
    if(cross(b, c) < -EPS) return -1; // "CLOCKWISE"
    if(dot(b, c) < 0) return +2;      // "ONLINE_BACK"
    if(norm(b) < norm(c)) return -2;  // "ONLINE_FRONT"
    return 0;                         // "ON_SEGMENT"
}


bool Intersect(const Segment &s, const Segment &t)
{
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}



int main() {
    double x, y, a, b, sx, sy, tx, ty;
    cin >> x >> y >> a >> b >> sx >> sy >> tx >> ty;
    complex<double> p(0, a), q(x, b), r(sx, sy), s(tx, ty);
    Segment A(p, q), B(r, s);
    puts(Intersect(A, B) ? "Yes" : "No");
    return 0;
}