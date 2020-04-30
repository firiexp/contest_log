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

bool isOrthogonal(Segment s, Segment t){
    return fabs(dot(s.b-s.a, t.b-t.a)) < EPS;
}

bool isparallel(Segment s, Segment t){
    return fabs(cross(s.b-s.a, t.b-t.a)) < EPS;
}


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

Polygon crossPoint(Circle c, Line l){
    Point p = project(l, c.c), q = (l.b-l.a)/abs(l.b-l.a);
    if(abs(distance(l, c.c)-c.r) < EPS){
        return {p};
    }
    double k = sqrt(c.r*c.r-dot(p-c.c, p-c.c));
    return {p-q*k, p+q*k};
}

Polygon crossPoint(Circle c, Segment s){
    auto tmp = crossPoint(c, Line(s.a, s.b));
    Polygon ret;
    for (auto &&i : tmp) {
        if(distance(s, i) < EPS) ret.emplace_back(i);
    }
    return ret;
}


Polygon crossPoint(Circle c1, Circle c2){
    double d = abs(c1.c-c2.c);
    double a = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    double t = arg(c2.c-c1.c);
    return {c1.c+polar(c1.r, t+a), c1.c+polar(c1.r, t-a)};
}

Polygon tangent(Circle c1, Point p){
    Circle c2 = Circle(p, sqrt(dot(c1.c-p, c1.c-p)-c1.r*c1.r));
    return crossPoint(c1, c2);
}
vector<Line> tangent(Circle c1, Circle c2){
    vector<Line> ret;
    if(c1.r < c2.r) swap(c1, c2);
    double k = dot(c1.c-c2.c, c1.c-c2.c);
    if(abs(k) < EPS) return {};
    Point u = (c2.c-c1.c)/sqrt(k);
    Point v(-u.y, u.x);
    for (auto &&i : {-1, 1}) {
        double h = (c1.r+i*c2.r)/sqrt(k);
        if(abs(h*h-1) < EPS){
            ret.emplace_back(c1.c+u*c1.r, c1.c+(u+v)*c1.r);
        }else if(h*h < 1){
            Point u2 = u*h, v2 = v*sqrt(1-h*h);
            ret.emplace_back(c1.c+(u2+v2)*c1.r, c2.c-(u2+v2)*c2.r*i);
            ret.emplace_back(c1.c+(u2-v2)*c1.r, c2.c-(u2-v2)*c2.r*i);
        }
    }
    return ret;
}

real area(Polygon v){
    if(v.size() < 3) return 0.0;
    real ans = 0.0;
    for (int i = 0; i < v.size(); ++i) {
        ans += cross(v[i], v[(i+1)%v.size()]);
    }
    return ans/2;
}

real area(Circle c, Polygon &v){
    int n = v.size();
    real ans = 0.0;
    Polygon u;
    for (int i = 0; i < n; ++i) {
        u.emplace_back(v[i]);
        auto q = crossPoint(c, Segment(v[i], v[(i+1)%n]));
        for (auto &&j : q) {
            u.emplace_back(j);
        }
    }
    for (int i = 0; i < u.size(); ++i) {
        Point A = u[i]-c.c, B = u[(i+1)%u.size()]-c.c;
        if(abs(A) >= c.r+EPS || abs(B) >= c.r+EPS){
            Point C = polar(1, arg(B)-arg(A));
            ans += c.r*c.r*arg(C)/2;
        }else {
            ans += cross(A, B)/2;
        }
    }
    return ans;
}

Polygon convex_hull(Polygon v){
    int n = v.size();
    sort(v.begin(),v.end(), sorty);
    int k = 0;
    Polygon ret(n*2);
    for (int i = 0; i < n; ++i) {
        while(k > 1 && cross(ret[k-1]-ret[k-2], v[i]-ret[k-1]) < 0) k--;
        ret[k++] = v[i];
    }
    for(int i = n-2, t=k; i >= 0; i--){
        while(k > t && cross(ret[k-1]-ret[k-2], v[i]-ret[k-1]) < 0) k--;
        ret[k++] = v[i];
    }
    ret.resize(k-1);
    return ret;
}


class UnionFind {
    int n;
    vector<int> uni;
    int forest_size;
public:
    explicit UnionFind(int n) : n(n), uni(static_cast<u32>(n), -1), forest_size(n) {};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        forest_size--;
        return true;
    }
    int size(){ return forest_size; }
    int size(int i){ return -uni[root(i)]; }
    bool same(int a, int b) { return root(a) == root(b); }
};

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> v(n);
    map<Point, int> M;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        M[v[i]] = i;
    }
    double ans = 0;
    auto C = convex_hull(v);
    for (int i = 0; i < C.size(); ++i) {
        ans += abs(C[i]-C[(i+1)%C.size()]);
        uf.unite(M[C[i]], M[C[(i+1)%C.size()]]);
    }
    vector<edge<double>> G;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G.emplace_back(a, b, abs(v[a]-v[b]));
    }
    sort(begin(G), end(G), [](const edge<double> &a, const edge<double> &b) { return a.cost < b.cost; });
    for(auto &e : G) if(uf.unite(e.from, e.to)) ans += e.cost;
    printf("%.15lf\n", ans);
    return 0;
}