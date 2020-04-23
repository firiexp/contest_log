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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> h[i+1];
    }
    auto dp = make_v(n+1, x+1, INF<ll>);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k+(i-j-1) <= x; ++k) {
                chmin(dp[i][k+(i-j-1)], dp[j][k] + abs(h[j]-h[i]));
            }
        }
    }
    ll ans = INF<ll>;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k+(n-j) <= x; ++k) {
            chmin(ans, dp[j][k] + h[j]);
        }
    }
    cout << ans/2 << "\n";
    return 0;
}