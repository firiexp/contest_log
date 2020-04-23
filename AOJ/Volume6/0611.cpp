#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

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
    int n, m;
    cin >> n >> m;
    vector<int> d(n), c(m);
    for (auto &&i : d) scanf("%d", &i);
    for (auto &&j : c) scanf("%d", &j);
    auto dp = make_v(m+1, n+1, INF<int>);
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j != n) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+d[j]*c[i]);
        }
    }
    cout << dp[m][n] << "\n";

    return 0;
}
