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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

using ld = double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P& a, const P& b) { return a.real()*b.imag() - a.imag()*b.real(); }
ld dot(const P& a, const P& b) { return a.real()*b.real() + a.imag()*b.imag(); }

using C = pair<ld, P>;
#define rad first
#define pnt second

C smallest_enclosing_disc(vector<P> ps) {
    auto c3 = [](const P &a, const P &b, const P &c) {
        ld A = norm(b - c);
        ld B = norm(c - a);
        ld C = norm(a - b);
        ld S = abs(cross(b - a, c - a));
        P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4 * S * S);
        ld r = abs(p - a);
        return make_pair(r, p);
    };

    auto c2 = [](const P &a, const P &b) {
        P c = (a + b) / (ld) 2;
        ld r = abs(a - c);
        return make_pair(r, c);
    };

    auto in_circle = [](const P &a, const C &c) {
        return norm(a - c.pnt) <= c.rad * c.rad + eps;
    };

    int n = ps.size();
    random_shuffle(ps.begin(), ps.end());
    C c = c2(ps[0], ps[1]);
    for (int i = 2; i < n; ++i) {
        if (!in_circle(ps[i], c)) {
            c = c2(ps[0], ps[i]);
            for (int j = 1; j < i; ++j) {
                if (!in_circle(ps[j], c)) {
                    c = c2(ps[j], ps[i]);
                    for (int k = 0; k < j; ++k) {
                        if (!in_circle(ps[k], c)) {
                            c = c3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}
int main() {
    int n;
    cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    auto x = smallest_enclosing_disc(v);
    printf("%.15lf\n", x.first);
    return 0;
}