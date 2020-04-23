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
    int n, d, x;
    cin >> n >> d >> x;
    auto v = make_v(d, n, 0);
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    int M = 100001;
    auto dp = make_v(d, M, -INF<int>);
    dp[0][x] = x;
    for (int i = 1; i < d; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = 0; j < n; ++j) {
            if(v[i][j] <= v[i-1][j]) continue;
            for (int k = v[i][j]-v[i-1][j]; k < M; ++k) {
                dp[i][k] = max(dp[i][k], dp[i-1][k+v[i-1][j]-v[i][j]]-v[i-1][j]);
                dp[i][k] = max(dp[i][k], dp[i][k+v[i-1][j]-v[i][j]]-v[i-1][j]);
            }
        }
        for (int j = 0; j < M; ++j) {
            if(dp[i][j] >= 0) dp[i][j] = j;
        }
    }
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        if(dp[d-1][i] >= 0) ans = i;
    }
    cout << ans << "\n";
    return 0;
}