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

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> s(n+1);
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i]^v[i];
    }
    ll ans = 1;
    vector<ll> dp(1<<20, 0), dq(1<<20, 1), zeros(1<<20, 0);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(s[i] == 0) cnt++;
        else {
            (dq[s[i]] += dp[s[i]]*(cnt-zeros[s[i]])) %= MOD;
            (dp[s[i]] += dq[s[i]]) %= MOD;
            zeros[s[i]] = cnt;
        }
    }
    if(s.back() != 0) cout << dq[s.back()] << "\n";
    else {
        ans = pow_(2, cnt-1, MOD);
        ans = accumulate(dp.begin(),dp.end(), ans);
        cout << ans%MOD << "\n";
    }
    return 0;
}