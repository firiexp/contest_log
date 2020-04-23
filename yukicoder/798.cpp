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
    int n;
    cin >> n;
    int notp = 0, p = 10000;
    while(p - notp > 1){
        int m = (p+notp)/2;
        int mm = m+(m/2);
        (n <= mm ? p : notp) = m;
    }
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    sort(v.begin(), v.end(), greater<>());
    auto dp = make_v(p+1, n+1, INF<ll>);
    dp[0][0] = 0;
    for (ll i = 0; i < p; ++i) {
        ll x = INF<ll>;
        for (ll j = 0; j < n; ++j) {
            chmin(x, dp[i][j]);
            if(x == INF<ll>) continue;
            dp[i+1][j+1] = x + v[j].second + i*v[j].first;
        }
    }
    ll ans = INF<ll>;
    for (int i = 0; i <= n; ++i) {
        chmin(ans, dp[p][i]);
    }
    cout << ans << "\n";
    return 0;
}
