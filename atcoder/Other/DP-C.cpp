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
    auto c = make_v(n, 3, 0);
    for (auto &&i : c) {
        for (auto &&j : i) {
            scanf("%d", &j);
        }
    }
    auto dp = make_v(n+1, 3, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + c[i-1][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << "\n";
    return 0;
}
