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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto dp = make_v(2, n+1, k+1, -1LL);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now = i&1, nxt = now^1;
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= k; ++l) {
                dp[nxt][j][l] = -1;
            }
        }
        for (int j = 0; j <= i; ++j) {
            for (int l = 0; l < k; ++l) {
                if(dp[now][j][l] == -1) continue;
                chmax(dp[nxt][j+1][0], dp[now][j][l] + v[i]);
                chmax(dp[nxt][j][l+1], dp[now][j][l]);
            }
        }
    }
    ll ans = -1;
    for (int i = 0; i < k; ++i) {
        chmax(ans, dp[n%2][m][i]);
    }
    cout << ans << "\n";
    return 0;
}