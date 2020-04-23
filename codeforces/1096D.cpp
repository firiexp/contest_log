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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n; string s, t = "hard";
    cin >> n >> s;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    auto dp = make_v(n+1, 5, INF<ll>);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            chmin(dp[i+1][j], dp[i][j]+v[i]);
            chmin(dp[i+1][j+(s[i] == t[j])], dp[i][j]);
        }
    }
    ll ans = INF<ll>;
    for (int i = 0; i < 4; ++i) {
        chmin(ans, dp.back()[i]);
    }
    cout << ans << "\n";
    return 0;
}