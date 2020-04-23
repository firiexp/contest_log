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
    string s;
    cin >> s;
    int n = s.size();
    auto dp = make_v(n+1, 2, n+1, 0LL);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < n; ++k) {
                int x = j ? 9 : s[i] - '0';
                for (int d = 0; d <= x; ++d) {
                    dp[i+1][j || d < x][k+(d == 1)] += dp[i][j][k];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans += dp[n][j][i]*i;
        }
    }
    cout << ans << "\n";
    return 0;
}
