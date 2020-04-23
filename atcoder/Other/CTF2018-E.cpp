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

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

int main() {
    size_t m = 600;
    int n;
    cin >> n;
    vector<int> v(n+15, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    auto dp = make_v(n+16, m+1, 0);
    dp[0][0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n+15; ++i) {
        for (int j = 0; j <= m; j += 2) {
            for (int k = 0; k <= v[i-1]; ++k) {
                (dp[i][j/2+k] += dp[i-1][j]) %= MOD;
            }
        }
        (ans += dp[i][1]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
