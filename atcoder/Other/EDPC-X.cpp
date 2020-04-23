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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    int n;
    cin >> n;
    using P = array<ll, 3>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        ll w, s, x;
        cin >> w >> s >> x;
        v[i] = {w, s, x};
    }
    sort(v.begin(), v.end(), [&](P a, P b){ return a[0]+a[1] < b[0]+b[1]; });
    vector<array<ll, 10002>> dp(2);
    fill(dp[0].begin(), dp[0].end(), -INF<ll>);
    dp[0][0] = 0;
    ll UPPER = 10001;
    for (int i = 0; i < n; ++i) {
        int now = i&1, nxt = now^1;
        fill(dp[nxt].begin(), dp[nxt].end(), -INF<ll>);
        for (int j = 0; j <= UPPER; ++j) {
            if(dp[now][j] == -INF<ll>) continue;
            chmax(dp[nxt][j], dp[now][j]);
            if(j <= v[i][1]) chmax(dp[nxt][min(UPPER, j+v[i][0])], dp[now][j]+v[i][2]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= UPPER; ++i) {
        chmax(ans, dp[n&1][i]);
    }
    cout << ans << "\n";
    return 0;
}
