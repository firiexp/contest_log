#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
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
    int n, d;
    cin >> n >> d;
    auto dp = make_v(n+1, 2, -INF<int>);
    auto x = make_v(n, 2, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &x[i][j]);
        }
    }
    dp[0][0] = 0; dp[0][1] = -d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                chmax(dp[i+1][j], dp[i][k] - (j != k) * d+ x[i][j]);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}
