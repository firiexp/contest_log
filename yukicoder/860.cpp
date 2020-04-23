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
    int n;
    cin >> n;
    vector<int> c(n), d(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &c[i], &d[i]);
    }
    auto dp = make_v(3, n+1, INF<ll>);
    dp[2][0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[0][i+1] = min(dp[0][i]+c[i]+d[i], dp[2][i]+c[i]);
        dp[1][i+1] = min({dp[0][i]+c[i]+c[i]+d[i], dp[1][i]+c[i]+d[i], dp[2][i]+c[i]+c[i]});
        dp[2][i+1] = dp[1][i+1];
    }
    cout << dp[2].back() << "\n";
    return 0;
}