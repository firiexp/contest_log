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
static const double EPS = 1e-10;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<double> xs(n), ys(n), cs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf %lf", &xs[i], &ys[i], &cs[i]);
    }
    double ng = -1, ok = INF<int>;
    for (int q = 0; q < 100; ++q) {
        auto mid = (ok+ng)/2;
        if(mid < 0) {
            ng = mid;
            continue;
        }
        double lx = -INF<int>, rx = INF<int>, ly = -INF<int>, ry = INF<int>;
        for (int i = 0; i < n; ++i) {
            lx = max(lx, xs[i]-mid/cs[i]);
            rx = min(rx, xs[i]+mid/cs[i]);
            ly = max(ly, ys[i]-mid/cs[i]);
            ry = min(ry, ys[i]+mid/cs[i]);
        }
        if(lx <= rx+EPS && ly <= ry+EPS) ok = mid;
        else ng = mid;
    }
    cout << setprecision(15) << ok << "\n";
    return 0;
}