#include <iostream>
#include <algorithm>
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
    int n, m;
    cin >> n >> m;
    vector<int> vs(n), hs(n), ts(m), ss(m);
    vector<int> vsum(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> vs[i] >> hs[i];
        vsum[i+1] = vsum[i]+vs[i];
    }
    for (int i = 0; i < m; ++i) cin >> ts[i] >> ss[i];
    auto dp = make_v(m+1, n+1, -INF<ll>);

    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        ll val1 = -INF<ll>, val2 = dp[i-1][0];
        for (int j = 0; j <= n; ++j) {
            if(j){
                val1 += hs[j-1]; val2 += hs[j-1];
                if(j >= 2){
                    val1 += abs(hs[j-1]-hs[j-2]);
                }
            }
            val1 = max(val1, val2);
            val2 = dp[i-1][j];
            if(ts[i-1] >= vsum[j]) dp[i][j] = max(val1, val2);
            if(dp[i][j] < ss[i-1]) dp[i][j] = -INF<ll>;
        }
    }
    int ans = ts.back();
    for (int i = 0; i <= n; ++i) {
        if(dp.back()[i] >= 0){
            cout << ans << "\n";
            return 0;
        }
        if(i != n) ans -= vs[i];
    }
    cout << -1 << "\n";
    return 0;
}