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
    int n, w;
    cin >> n >> w;
    auto dp = make_v(n+1, 100001, INF<int>);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = make_pair(a, b);
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        tie(a, b) = v[i];
        for (int j = 0; j <= 100000; ++j) {
            if(j >= b) dp[i+1][j] = min(dp[i+1][j], dp[i][j-b] + a);
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100000; ++i) {
        if(dp[n][i] <= w) ans = max(ans, i);
    }
    cout << ans << "\n";
    return 0;
}
