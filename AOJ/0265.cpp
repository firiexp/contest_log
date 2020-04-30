#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using real = double;
static constexpr real EPS = 1e-10;
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

bool sorty(Point a, Point b){
    return (a.y != b.y ? a.y < b.y : a.x < b.x);
}

istream& operator>> (istream& s, Point& P){
    s >> P.x >> P.y;
    return s;
}

inline real dot(Point a, Point b){ return a.x*b.x + a.y*b.y; }
inline real cross(Point a, Point b){ return a.x*b.y - a.y*b.x; }
inline real abs(Point a){ return sqrt(dot(a, a)); }


real angle(Point A, Point B){
    return acos(dot(A, B)/abs(A)/abs(B));
}



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

struct Line {
    Point a, b;
    Line(Point x, Point y) : a(x), b(y) {};
};

struct Circle{
    Point c; real r;
    Circle(Point c, real r): c(c), r(r) {};
};

using Polygon = vector<Point>;

bool intersect(Segment s, Segment t){
    return (ccw(s.a, s.b, t.a)*ccw(s.a, s.b, t.b) <= 0 &&
            ccw(t.a, t.b, s.a)*ccw(t.a, t.b, s.b) <= 0);
}

bool intersect(Segment s, Line t){
    int a = ccw(t.a, t.b, s.a), b = ccw(t.a, t.b, s.b);
    return (!(a&1) || !(b&1) || a != b);
}

Point polar(double r, double t){
    return Point(r*cos(t), r*sin(t));
}

double arg(Point p){
    return atan2(p.y, p.x);
}

static constexpr int CONTAIN = 0;
static constexpr int INSCRIBE = 1;
static constexpr int INTERSECT = 2;
static constexpr int CIRCUMSCRIBED = 3;
static constexpr int SEPARATE = 4;

int intersect(Circle c1, Circle c2){
    if(c1.r < c2.r) swap(c1, c2);
    real d = abs(c1.c-c2.c);
    real r = c1.r + c2.r;
    if(fabs(d-r) < EPS) return CIRCUMSCRIBED;
    if(d > r) return SEPARATE;
    if(fabs(d+c2.r-c1.r) < EPS) return INSCRIBE;
    if(d+c2.r < c1.r) return CONTAIN;
    return INTERSECT;
}

real distance(Line l, Point c){
    return abs(cross(l.b-l.a, c-l.a)/abs(l.b-l.a));
}


real distance(Segment s, Point c){
    if(dot(s.b-s.a, c-s.a) < EPS) return abs(c-s.a);
    if(dot(s.a-s.b, c-s.b) < EPS) return abs(c-s.b);
    return abs(cross(s.b-s.a, c-s.a)) / abs(s.a-s.b);
}

real distance(Segment s, Segment t){
    if(intersect(s, t)) return 0.0;
    return min({distance(s, t.a), distance(s, t.b),
                distance(t, s.a), distance(t, s.b)});
}


Point project(Line l, Point p){
    Point Q = l.b-l.a;
    return l.a + Q*(dot(p-l.a, Q) / dot(Q, Q));
}


Point project(Segment s, Point p){
    Point Q = s.b-s.a;
    return s.a + Q*(dot(p-s.a, Q) / dot(Q, Q));
}

Point refrect(Segment s, Point p){
    Point Q = project(s, p);
    return Q*2-p;
}

bool isOrthogonal(Segment s, Segment t) { return fabs(dot(s.b-s.a, t.b-t.a)) < EPS; }

bool isparallel(Segment s, Segment t) {return fabs(cross(s.b-s.a, t.b-t.a)) < EPS;}
bool isparallel(Segment s, Line t) {return fabs(cross(s.b-s.a, t.b-t.a)) < EPS;}
bool isparallel(Line s, Line t) {return fabs(cross(s.b-s.a, t.b-t.a)) < EPS;}

Point crossPoint(Segment s, Segment t){
    real d1 = cross(s.b-s.a, t.b-t.a);
    real d2 = cross(s.b-s.a, s.b-t.a);
    if(fabs(d1) < EPS && fabs(d2) < EPS) return t.a;
    return t.a+(t.b-t.a)*d2/d1;
}

Point crossPoint(Line s, Line t){
    real d1 = cross(s.b-s.a, t.b-t.a);
    real d2 = cross(s.b-s.a, s.b-t.a);
    if(fabs(d1) < EPS && fabs(d2) < EPS) return t.a;
    return t.a+(t.b-t.a)*d2/d1;
}

Point crossPoint(Segment s, Line t){
    real d1 = cross(s.b-s.a, t.b-t.a);
    real d2 = cross(s.b-s.a, s.b-t.a);
    if(fabs(d1) < EPS && fabs(d2) < EPS) return t.a;
    return t.a+(t.b-t.a)*d2/d1;
}

int contains(Polygon v, Point p){
    int n = v.size();
    bool x = false;
    static constexpr int IN = 2;
    static constexpr int ON = 1;
    static constexpr int OUT = 0;
    for (int i = 0; i < n; ++i) {
        Point a = v[i]-p, b = v[(i+1)%n]-p;
        if(fabs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON;
        if(a.y > b.y) swap(a, b);
        if(a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return (x?IN:OUT);
}




void solve(int n){
    Polygon p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector<Segment> S;
    for (int i = 0; i < n; ++i) {
        S.emplace_back(p[i], p[(i + 1) % n]);
    }
    vector<Polygon> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].emplace_back(p[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            int ok = 1;
            Line L(p[i], p[j]);
            real val = 1e100;
            int cur = 0;
            for (int k = 0; k < n && ok; ++k) {
                if(k == i || (k+1)%n == i || k == j || (k+1)%n == j) continue;
                if(!intersect(S[k], L) || isparallel(S[k], L)) continue;
                auto P = crossPoint(S[k], L);
                real w = dot(P-p[i], p[j]-p[i])/dot(p[j]-p[i], p[j]-p[i]);
                if(w < EPS) continue;
                else if(w < 1-EPS) ok = 0;
                else if(w < val){
                    val = w;
                    cur = k;
                }
            }
            if(ok && val < 1e9) {
                a[cur].emplace_back(p[i]+(p[j]-p[i])*val);
            }
        }
    }
    Polygon W;
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(),a[i].end(), [&](Point x, Point y){ return abs(p[i]-x) < abs(p[i]-y); });
        for (int j = 0; j < a[i].size(); ++j) {
            W.emplace_back(a[i][j]);
            if(j+1 < a[i].size()){
                W.emplace_back((a[i][j]+a[i][j+1])/2);
            }
        }
    }
    using B = bitset<600>;
    vector<B> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < W.size(); ++j) {
            int ok = contains(p, (p[i]+W[j])/2);
            Segment L(p[i], W[j]);
            for (int k = 0; k < n && ok; ++k) {
                if(k == i || (k+1)%n == i || k == j || (k+1)%n == j) continue;
                if(!intersect(S[k], L) || isparallel(S[k], L)) continue;
                auto P = crossPoint(S[k], L);
                if(abs(P-S[k].a) > EPS && abs(P-S[k].b) > EPS && abs(P-L.a) > EPS && abs(P-L.b) > EPS){
                    ok = 0;
                }
            }
            if(ok) v[i].set(j);
        }
    }
    int ans = (n+1)/2;
    B A;
    vector<int> aa;
    auto dfs = [&](int cur, int cnt, B x, auto &&f) -> void {
        if(cur >= n || cnt >= ans) return;
        if(x.count() == W.size()) {
            ans = cnt;
            return;
        }
        f(cur+1, cnt, x, f);
        x |= v[cur];
        aa.emplace_back(cur);
        f(cur+1, cnt+1, x, f);
        aa.pop_back();
    };
    dfs(0, 0, A, dfs);
    cout << ans << "\n";
}

int main() {
    int n;
    while(cin >> n, n){
        solve(n);
    }
    return 0;
}
