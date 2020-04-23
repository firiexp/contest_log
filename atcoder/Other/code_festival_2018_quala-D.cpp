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

int main() {
    ll d, f, t, n;
    cin >> d >> f >> t >> n;
    vector<ll> v(n+1);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        v[i+1] = x;
    }
    vector<ll> pow2(n+1, 1);
    for (int i = 0; i < n; ++i) {
        pow2[i+1] = (pow2[i]<<1) % MOD;
    }
    vector<ll> cnt(n+1);
    for (int i = 0; i <= n; ++i) {
        int r = upper_bound(v.begin(), v.end(), v[i]+f-t) - v.begin();
        cnt[i] = pow2[r-i-1];
    }
    vector<ll> dp(n+1, 0), sum(n+2, 0);
    dp[0] = 1; sum[1] = cnt[0];
    for (int i = 1; i <= n; ++i) {
        int l = lower_bound(v.begin(), v.end(), v[i]-f) - v.begin(),
            r = lower_bound(v.begin(), v.end(), v[i]-f+t) - v.begin();
        dp[i] = (sum[r]-sum[l]+MOD)%MOD;
        sum[i+1] = (sum[i]+dp[i]*cnt[i])%MOD;
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        if(d - v[i] <= f) (ans += dp[i]*cnt[i]) %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
