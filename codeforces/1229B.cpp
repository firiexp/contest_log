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
    int n;
    cin >> n;
    auto dp = make_v(18, n, -1);
    auto dp2 =  make_v(18, n, (ll)0);
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a-1].emplace_back(b-1);
        G[b-1].emplace_back(a-1);
    }

    auto dfs = [&](auto &&f, int x, int par) -> void {
        dp[0][x] = par;
        if(par != -1) dp2[0][x] = __gcd(v[x], v[par]);
        for (auto &&i : G[x]) {
            if(i != par) f(f, i, x);
        }
    };
    dfs(dfs, 0, -1);
    for (int i = 1; i < 18; ++i) {
        for (int j = 0; j < n; ++j) {
            if(dp[i-1][j] != -1) {
                dp[i][j] = dp[i-1][dp[i-1][j]];
                dp2[i][j] = __gcd(dp2[i-1][j], dp2[i-1][dp[i-1][j]]);
            }
            else dp[i-1][j] = -1, dp2[i][j] = dp2[i-1][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = i;
        ll val = v[i];
        while(cur != -1){
            int p = 1;
            for (int j = 17; j >= 0; --j) {
                if(dp[j][cur] != -1 && __gcd(dp2[j][cur], val) == val) {
                     p += 1 << j;
                     cur = dp[j][cur];
                }
            }
            (ans += val * p) %= MOD;
            val = __gcd(val, dp2[0][cur]);
            cur = dp[0][cur];
        }
    }
    cout << ans << "\n";
    return 0;
}