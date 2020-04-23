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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, r);
    }
    auto dp = make_v(k+1, n+1, (ll)0);
    fill(dp[0].begin(), dp[0].end(), 1);
    dp[0][0] = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            int l, r;
            tie(l, r) = v[j];
            ll x = (dp[i][r] - dp[i][l-1] + MOD) % MOD;
            (dp[i+1][l] += x) %= MOD;
            if(r != n) (dp[i+1][r+1] += MOD-x) %= MOD;
        }
        for (int j = 0; j < n; ++j) {
            (dp[i+1][j+1] += dp[i+1][j]) %= MOD;
        }
        for (int j = 0; j < n; ++j) {
            (dp[i+1][j+1] += dp[i+1][j]) %= MOD;
        }
    }
    cout << (dp[k][n] - dp[k][n-1]+MOD) % MOD << "\n";
    return 0;
}
