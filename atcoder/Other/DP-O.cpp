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
    auto v = make_v(n, n, 0);
    for (auto &&i : v) {
        for (auto &&j : i) {
            scanf("%d", &j);
        }
    }
    vector<vector<int>> t(n+1);
    vector<int> dp(1 << n, 0);
    for (int i = 0; i < (1 << n); ++i) {
        t[__builtin_popcount(i)].emplace_back(i);
    }
    dp[0] = 1;
    for (int p = 0; p < n; ++p) {
        for (auto &&i : t[p]) {
            for (int j = 0; j < n; ++j) {
                if (!(i & (1<<j)) && v[p][j]) {
                    (dp[i | (1<<j)] += dp[i]) %= MOD;
                }
            }
        }
    }
    cout << dp[(1 << n)-1] << "\n";
    return 0;
}
