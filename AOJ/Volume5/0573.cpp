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
    int n, t, s;
    cin >> n >> t >> s;
    t -= s;
    auto dp1 = make_v(n+1, s+1, 0ll);
    auto dp2 = make_v(n+1, t+1, 0ll);
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= s; ++j) {
            chmax(dp1[i][j], dp1[i][j-1]);
            chmax(dp1[i+1][j], dp1[i][j]);
        }
        for (int j = 0; j <= s; ++j) {
            if(j+b[i] > s) break;
            chmax(dp1[i+1][j+b[i]], dp1[i][j]+a[i]);
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= t; ++j) {
            chmax(dp2[i][j], dp2[i][j-1]);
            chmax(dp2[i+1][j], dp2[i][j]);
        }
        for (int j = 0; j <= t; ++j) {
            if(j+b[i] > t) break;
            chmax(dp2[i+1][j+b[i]], dp2[i][j]+a[i]);
        }
    }
    reverse(dp2.begin(), dp2.end());
    ll ans = 0;
    for (int i = 0; i <= n+1; ++i) {
        ll x = 0;
        if(i) x += dp1[i-1][s];
        if(i <= n) x += dp2[i][t];
        chmax(ans, x);
    }
    cout << ans << "\n";
    return 0;
}
