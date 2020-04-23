#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

struct point {
    double x, y, r;
    point(double xx, double yy, double rr) :x(xx), y(yy), r(rr) {};
};

int main() {
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    int n;
    cin >> n;

    auto d = make_v(n+2, n+2, 0.0);
    vector<point> v;
    vector<double> ans(n+2, INF<double>);
    vector<int> used(n+2, 0);
    ans[0] = 0;

    v.emplace_back(xs, ys, 0.0);


    for (int i = 1; i <= n; ++i) {
        double x, y, r;
        scanf("%lf %lf %lf", &x, &y ,&r);
        v.emplace_back(x, y, r);
    }
    v.emplace_back(xt, yt, 0.0);

    for (int i = 0; i <= n+1; ++i) {
        for (int j = i+1; j <= n+1; ++j) {
            if(i == j) continue;
            d[i][j] = d[j][i] = max(0.0, hypot(fabs(v[i].x-v[j].x), fabs(v[i].y-v[j].y))-v[i].r-v[j].r);
        }
    }
    while(true){
        int x = -1;
        for (int u = 0; u < n+2; ++u) {
            if(!used[u] && (x == -1 || ans[u] < ans[x])) x = u;
        }
        if(x == -1) break;
        used[x] = true;
        for (int u = 0; u < n+2; ++u) {
            ans[u] = min(ans[u], ans[x] + d[x][u]);
        }
    }
     cout << setprecision(11) <<  ans[n+1] << "\n";

    return 0;
}
