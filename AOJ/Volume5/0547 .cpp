#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 100000;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int w, h;
    cin >> w >> h;
    auto dp = make_v(h+1, w+1, 2, 2, 0);
    for (int i = 0; i <= h; ++i) dp[i][0][0][0] = 1;
    for (int i = 0; i <= w; ++i) dp[0][i][1][0] = 1;
    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            (dp[i][j][0][0] += dp[i-1][j][0][0] + dp[i-1][j][0][1]) %= MOD;
            (dp[i][j][0][1] += dp[i-1][j][1][0]) %= MOD;
            (dp[i][j][1][0] += dp[i][j-1][1][0] + dp[i][j-1][1][1]) %= MOD;
            (dp[i][j][1][1] += dp[i][j-1][0][0]) %= MOD;
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            (ans += dp[h-1][w-1][i][j]) %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
