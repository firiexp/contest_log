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
struct Point {
    real x, y;
    Point& operator+=(const Point a) { x += a.x; y += a.y;  return *this; }
    Point& operator-=(const Point a) { x -= a.x; y -= a.y;  return *this; }
    Point& operator*=(const real k) { x *= k; y *= k;  return *this; }
    Point& operator/=(const real k) { x /= k; y /= k;  return *this; }
    Point operator+(const Point a) const {return Point(*this) += a; }
    Point operator-(const Point a) const {return Point(*this) -= a; }
    Point operator*(const real k) const {return Point(*this) *= k; }
    Point operator/(const real k) const {return Point(*this) /= k; }
    bool operator<(const Point &a) const { return (x != a.x ? x < a.x : y < a.y); }
    explicit Point(real a = 0, real b = 0) : x(a), y(b) {};
};





istream& operator>> (istream& s, Point& P){
    s >> P.x >> P.y;
    return s;
}

inline real dot(Point a, Point b){ return a.x*b.x + a.y*b.y; }
inline real cross(Point a, Point b){ return a.x*b.y - a.y*b.x; }
inline real abs(Point a){ return sqrt(dot(a, a)); }

static constexpr int COUNTER_CLOCKWISE = 1;
static constexpr int CLOCKWISE = -1;
static constexpr int ONLINE_BACK = 2;
static constexpr int ONLINE_FRONT = -2;
static constexpr int ON_SEGMENT = 0;

int ccw(Point a, Point b, Point c){
    b -= a; c -= a;
    if(cross(b, c) > EPS) return COUNTER_CLOCKWISE;
    if(cross(b, c) < -EPS) return CLOCKWISE;
    if(dot(b, c) < 0) return ONLINE_BACK;
    if(abs(b) < abs(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}
struct Segment {
    Point a, b;
    Segment(Point x, Point y) : a(x), b(y) {};
};

bool intersect(Segment s, Segment t){
    return (ccw(s.a, s.b, t.a)*ccw(s.a, s.b, t.b) <= 0 &&
            ccw(t.a, t.b, s.a)*ccw(t.a, t.b, s.b) <= 0);
}

double distance(Segment s, Point c){
    if(dot(s.b-s.a, c-s.a) < EPS) return abs(c-s.a);
    if(dot(s.a-s.b, c-s.b) < EPS) return abs(c-s.b);
    return abs(cross(s.b-s.a, c-s.a)) / abs(s.a-s.b);
}

double distance(Segment s, Segment t){
    if(intersect(s, t)) return 0.0;
    return min({distance(s, t.a), distance(s, t.b),
                distance(t, s.a), distance(t, s.b)});
}



Point crossPoint(Segment s, Segment t){
    real d1 = abs(cross(s.b-s.a, t.b-t.a));
    real d2 = abs(cross(s.b-s.a, s.b-t.a));
    if(d1 < EPS && d2 < EPS) return t.a;
    return t.a+(t.b-t.a)*d2/d1;
}

Point project(Segment s, Point p){
    Point Q = s.b-s.a;
    return s.a + Q*(dot(p-s.a, Q) / dot(Q, Q));
}

Point refrect(Segment s, Point p){
    Point Q = project(s, p);
    return Q*2-p;
}

bool isOrthogonal(Segment s, Segment t){
    return fabs(dot(s.b-s.a, t.b-t.a)) < EPS;
}

bool isparallel(Segment s, Segment t){
    return fabs(cross(s.b-s.a, t.b-t.a)) < EPS;
}

using polygon = vector<Point>;

real area(polygon &v){
    if(v.size() < 3) return 0.0;
    real ans = 0.0;
    for (int i = 0; i+1 < v.size(); ++i) {
        ans += cross(v[i], v[i+1]);
    }
    ans += cross(v.back(), v.front());
    return ans/2;
}

polygon convex_hull(polygon v){
    int n = v.size();
    sort(v.begin(),v.end());
    int k = 0;
    polygon ret(n*2);
    for (int i = 0; i < n; ++i) {
        while(k > 1 && cross(ret[k-1]-ret[k-2], v[k]-ret[k-1]) < 0) k--;
        ret[k++] = v[i];
    }
    for(int i = n-2, t=k; i >= 0; i--){
        while(k > t && cross(ret[k-1]-ret[k-2], v[i]-ret[k-1]) < 0) k--;
        ret[k++] = v[i];
    }
    ret.resize(k-1);
    return ret;
}

bool isconvex(polygon &P){
    int n = P.size();
    for (int i = 0; i < n; ++i) {
        if(ccw(P[(i+n-1)%n], P[i], P[(i+1)%n]) == CLOCKWISE) return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    polygon P(n);
    for(auto &&i : P) cin >> i;
    cout << isconvex(P) << "\n";
    return 0;
}