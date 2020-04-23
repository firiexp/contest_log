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

static const int MOD = 1000000000;
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
    ll n, m;
    cin >> n >> m;
    n /= 1000;
    n %= m;
    auto dp = make_v(2, n+1, 0);
    dp[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
        int now = i&1, prv = now^1;
        fill(dp[now].begin(),dp[now].end(), 0);
        dp[now][0] = 1;
        for (int j = 1; j <= n; ++j) {
            (dp[now][j] += dp[prv][j-1] + dp[prv][j]) %= MOD;
        }
    }ee
    cout << dp[m%2][n] << "\n";
    return 0;
}

