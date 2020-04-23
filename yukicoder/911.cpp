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
#pragma GCC target ("avx")
template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<ll> c(63, -1);
    for (int i = 0; i+1 < n; ++i) {
        int j = 63-__builtin_clzll(v[i]^v[i+1]);
        ll cc = ((v[i] >> j) & 1);
        if(c[j] == -1) c[j] = cc;
        else if(c[j] != cc){
            puts("0");
            return 0;
        }
    }
    ll ans = 0;
    auto dp = make_v(64, 2, 0LL);
    dp[63][0] = 1;
    for (int i = 62; i >= 0; --i) {
        ll p = (1LL & (r >> i));
        if(c[i] == -1){
            for (int j = 0; j < 2; ++j) {
                ll d = (j ? 1 : p);
                for (int k = 0; k <= d; ++k) {
                    dp[i][j | (k < d)] += dp[i+1][j];
                }
            }
        }else {
            for (int j = 0; j < 2; ++j) {
                ll d = (j ? 1 : p);
                for (int k = c[i]; k <= d && k < c[i]+1; ++k) {
                    dp[i][j | (k < d)] += dp[i+1][j];
                }
            }
        }
    }
    ans += dp[0][0] + dp[0][1];
    if(l != 0){
        dp = make_v(64, 2, 0LL);
        dp[63][0] = 1;
        for (int i = 62; i >= 0; --i) {
            ll p = (1LL & ((l-1) >> i));
            if(c[i] == -1){
                for (int j = 0; j < 2; ++j) {
                    ll d = (j ? 1 : p);
                    for (int k = 0; k <= d; ++k) {
                        dp[i][j | (k < d)] += dp[i+1][j];
                    }
                }
            }else {
                for (int j = 0; j < 2; ++j) {
                    ll d = (j ? 1 : p);
                    for (int k = c[i]; k <= d && k < c[i]+1; ++k) {
                        dp[i][j | (k < d)] += dp[i+1][j];
                    }
                }
            }
        }
        ans -= dp[0][0] + dp[0][1];
    }
    cout << ans << "\n";
    return 0;
}