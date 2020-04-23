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
real EPS = 1e-10;
struct Point3 {
    real x, y, z;
    Point3& operator+=(const Point3 a) { x += a.x; y += a.y; z += a.z;  return *this; }
    Point3& operator-=(const Point3 a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
    Point3 operator+(const Point3 a) const {return Point3(*this) += a; }
    Point3 operator-(const Point3 a) const {return Point3(*this) -= a; }
    explicit Point3(real a = 0, real b = 0, real c = 0) : x(a), y(b), z(c) {};
};


inline real dot(Point3 a, Point3 b){ return a.x*b.x + a.y*b.y + a.z*b.z; }
inline Point3 cross(Point3 a, Point3 b){
    return Point3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
inline real abs(Point3 a){ return sqrt(dot(a, a)); }

struct Segment {
    Point3 a, b;
    Segment(Point3 x, Point3 y) : a(x), b(y) {};
};


double distance(Segment l, Point3 c){
    if(dot(l.b-l.a, c-l.a) <= 0) return abs(c-l.a);
    if(dot(l.a-l.b, c-l.b) <= 0) return abs(c-l.b);
    return abs(cross(l.b-l.a, c-l.a)) / abs(l.a-l.b);
}

struct Sphere{
    Point3 c;
    double r;
    Sphere(){};
    Sphere(Point3 c, double r): c(c), r(r){};
};

bool intersect(Segment s,Sphere c){
    double d=distance(s,c.c);
    return d < c.r+EPS;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<Sphere> v(n);
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].c.x >> v[i].c.y >> v[i].c.z >> v[i].r >> x[i];
    }
    for (int i = 0; i < q; ++i) {
        double a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        Segment S(Point3(a, b, c), Point3(d, e, f));
        uint64_t ans = 0;
        for (int j = 0; j < n; ++j) {
            if(intersect(S, v[j])) ans += x[j];
        }
        cout << ans << "\n";
    }
    return 0;
}