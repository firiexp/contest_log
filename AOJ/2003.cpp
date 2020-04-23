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
    if(cross(b, c) < EPS) return CLOCKWISE;
    if(dot(b, c) < 0) return ONLINE_BACK;
    if(abs(b) < abs(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}
struct Segment {
    Point a, b;
    Segment(Point x, Point y) : a(x), b(y) {};
};

double distance(Segment l, Point c){
    if(dot(l.b-l.a, c-l.a) < EPS) return abs(c-l.a);
    if(dot(l.a-l.b, c-l.b) < EPS) return abs(c-l.b);
    return abs(cross(l.b-l.a, c-l.a)) / abs(l.a-l.b);
}

bool intersect(Segment s, Segment t){
    return (ccw(s.a, s.b, t.a)*ccw(s.a, s.b, t.b) <= 0 &&
            ccw(t.a, t.b, s.a)*ccw(t.a, t.b, s.b) <= 0);
}

Point crossPoint(Segment l1, Segment l2){
    real d1 = abs(cross(l1.b-l1.a, l2.b-l2.a));
    real d2 = abs(cross(l1.b-l1.a, l1.b-l2.a));
    if(d1 < EPS && d2 < EPS) return l2.a;
    return l2.a+(l2.b-l2.a)*d2/d1;
}

int main() {
    int q; cin >> q;
    while(q--){
        Point A, B; cin >> A >> B;
        Segment X(A, B);
        int n;
        cin >> n;
        vector<pair<real, int>> v;
        for (int i = 0; i < n; ++i) {
            Point P, Q; int o, l;
            cin >> P >> Q >> o >> l;
            Segment L(P, Q);
            if(intersect(X, L)){
                v.emplace_back(abs(crossPoint(X, L)-A), o^l^1);
            }
        }
        sort(v.begin(),v.end());
        int ans = INF<int>;
        for (int k = 0; k <= 1; ++k) {
            int cnt = 0, p = k;
            for (auto & i : v) {
                if(p != i.second) p ^= 1, cnt++;
            }
            ans = min(ans, cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}