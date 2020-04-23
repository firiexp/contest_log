#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 998244353;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

template <class T, size_t D> struct _Vec {
    using type = vector<typename _Vec<T, D-1>::type>;
};
template <class T> struct _Vec<T, 1> {
    using type = vector<T>;
};
template<class T, size_t D> using Vec = typename _Vec<T, D>::type;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}
int main() {
    int n, k;
    cin >> n >> k;
    Vec<u32, 3> dp = make_v(2, 2001, 4, (u32)0);
    dp[1][1][0] = 1, dp[1][2][1] = 1, dp[1][2][2] = 1, dp[1][1][3] = 1;
    for (int i = 1; i < n; ++i) {
        int now = i&1, nxt = (i&1)^1;
        dp[nxt] = make_v(2001, 4, (u32)0);
        for (int j = 1; j <= 2*i; ++j) {
            dp[nxt][j][0] = (dp[nxt][j][0] + dp[now][j][0] + dp[now][j][1] + dp[now][j][2])%MOD;
            dp[nxt][j+1][0] = (dp[nxt][j+1][0] + dp[now][j][3]) % MOD;
            dp[nxt][j][1] = (dp[nxt][j][1] + dp[now][j][1]) % MOD;
            dp[nxt][j+1][1] = (dp[nxt][j+1][1] + dp[now][j][0] + dp[now][j][3]) % MOD;
            dp[nxt][j+2][1] = (dp[nxt][j+2][1] + dp[now][j][2]) % MOD;
            dp[nxt][j][2] = (dp[nxt][j][2] + dp[now][j][2]) % MOD;
            dp[nxt][j+1][2] = (dp[nxt][j+1][2] + dp[now][j][0] + dp[now][j][3]) % MOD;
            dp[nxt][j+2][2] = (dp[nxt][j+2][2] + dp[now][j][1]) % MOD;
            dp[nxt][j][3] = (dp[nxt][j][3] + dp[now][j][1] + dp[now][j][2] + dp[now][j][3])%MOD;
            dp[nxt][j+1][3] = (dp[nxt][j+1][3] + dp[now][j][0]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans = (ans + dp[n&1][k][i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
