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

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using real = double;
static constexpr real EPS = 1e-10;
struct Point3 {
    real x, y, z;
    Point3& operator+=(const Point3 a) { x += a.x; y += a.y; z += a.z;  return *this; }
    Point3& operator-=(const Point3 a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
    Point3& operator*=(const real k) { x *= k; y *= k; z *= k;  return *this; }
    Point3& operator/=(const real k) { x /= k; y /= k; z /= k; return *this; }
    Point3 operator+(const Point3 a) const {return Point3(*this) += a; }
    Point3 operator-(const Point3 a) const {return Point3(*this) -= a; }
    Point3 operator*(const real k) const {return Point3(*this) *= k; }
    Point3 operator/(const real k) const {return Point3(*this) /= k; }
    Point3 (real a = 0, real b = 0, real c = 0) : x(a), y(b), z(c) {};
};

inline real dot(Point3 a, Point3 b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
inline real abs(Point3 a){ return sqrt(dot(a, a)); }
inline Point3 cross(Point3 a, Point3 b){ return {a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};  }

istream& operator>> (istream& s, Point3& P){
    s >> P.x >> P.y >> P.z;
    return s;
}

int main() {
    Point3 a, b, c, d;
    cin >> a >> b >> c >> d;
    b -= a, c -= a; d -= a;
    auto e = cross(b, c); e /= abs(e);
    auto h = d - e*dot(d, e);
    auto p = cross(b, h), q = cross(c-b, h-b), r = cross(c*(-1), h-c);
    if((dot(p, q) >= 0) == (dot(q, r) >= 0) && (dot(q, r) >= 0)== (dot(r, p) >= 0)) puts("YES");
    else puts("NO");
    return 0;
}