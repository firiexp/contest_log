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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T>
struct Point {
    T x, y;
    Point& operator+=(const Point a) { x += a.x; y += a.y;  return *this; }
    Point& operator-=(const Point a) { x -= a.x; y -= a.y;  return *this; }
    Point operator+(const Point a) const {return Point(*this) += a; }
    Point operator-(const Point a) const {return Point(*this) -= a; }
    bool operator<(const Point &a) const { return (x != a.x ? x < a.x : y < a.y); }
    T dot(Point a) { return x*a.x + y*a.y; }
    T cross(Point a) { return x*a.y - y*a.x; }
    T abs() { return sqrt(this->dot(*this)); }
    explicit Point(T a = 0,T b = 0) : x(a), y(b) {};

};

double EPS = 1e-9;
template <class T>
vector<Point<T>> convex_hull(vector<Point<T>> &v){
    size_t n = static_cast<int>(v.size()),  k = 0;
    if(n <= 2) return v;
    sort(v.begin(), v.end());
    vector<Point<T>> ret(2*n);
    for (int i = 0; i < n; ret[k++] = v[i++]) {
        while(k >= 2 && (ret[k-1]-ret[k-2]).cross(v[i]-ret[k-1]) < 0) k--;
    }
    for (int i = n-2, t = k+1; i >= 0; ret[k++] = v[i--]) {
        while(k >= t && (ret[k-1]-ret[k-2]).cross(v[i]-ret[k-1]) < 0) k--;
    }
    ret.resize(k-1);
    return ret;
}


int main() {
    int n;
    cin >> n;
    vector<Point<double>> v, u;
    for (int i = 0; i < n; ++i) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        v.emplace_back(a, b);
    }
    for (int i = 0; i < n; ++i) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        u.emplace_back(a, b);
    }
    auto c1 = convex_hull(v), c2 = convex_hull(u);
    double ans1 = (c1.front()-c1.back()).abs(), ans2 = (c2.front()-c2.back()).abs();
    for (int i = 0; i+1 < c1.size(); ++i) ans1 = min(ans1, (c1[i+1]-c1[i]).abs());
    for (int i = 0; i+1 < c2.size(); ++i) ans2 = min(ans2, (c2[i+1]-c2[i]).abs());
    cout << setprecision(10) << ans2/ans1 << "\n";
    return 0;
}
