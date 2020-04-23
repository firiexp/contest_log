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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto dp = make_v(n+1, k+1, 0);
    vector<int> sum(k+2, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j <= k; ++j) {
            (s += dp[i][j]) %= MOD;
            sum[j+1] = s;
        }
        for (int j = 0; j <= k; ++j) {
            (dp[i+1][j] = sum[j+1] - sum[max(0, j-v[i])]  + MOD) %= MOD;
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
