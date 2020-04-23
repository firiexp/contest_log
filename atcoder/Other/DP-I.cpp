#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

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


int main() {
    int n;
    cin >> n;
    vector<long double> v(n);
    for (auto &&i : v) scanf("%Lf", &i);
    auto dp = make_v(n+1, n+1, 0.0L);
    dp[0][0] = 1.0L;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i+1][j] += dp[i][j]*(1.0-v[i]);
            dp[i+1][j+1] += dp[i][j]*v[i];
        }
    }
    long double ans = 0.0L;
    for (int i = 0; i <= n; ++i) {
        if(2*i >= n) ans += dp[n][i];
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
