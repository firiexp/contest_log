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
    int n, m;
    cin >> n >> m;
    vector<int> v(n), u(m);
    for (auto &&i : v) scanf("%d", &i);
    for (auto &&j : u) scanf("%d", &j);
    auto dp = make_v(n+1, m+1, 0);
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if(i) (dp[i][j] += dp[i-1][j]) %= MOD;
            if(j) (dp[i][j] += dp[i][j-1]) %= MOD;
            if(i > 0 && j > 0){
                (dp[i][j] += MOD - dp[i-1][j-1]) %= MOD;
                if(v[i-1] == u[j-1]){
                    (dp[i][j] += dp[i-1][j-1]) %= MOD;
                }
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}