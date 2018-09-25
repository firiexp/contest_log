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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int r, n, m;
    cin >> r >> n >> m;
    long double ans = 0;
    auto f = [&](double x, double r, double n) {
        double k = x / n;
        if(x > n || x < 0) return 0.0;
        return 4.0 * r * sqrt(k - k * k);
    };
    auto nn = double(n);
    for (int i = 0; i < n+m; ++i) {
        auto x = double(i);
        ans += max(f(x, r, nn),f(x-double(m), r, nn));
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
