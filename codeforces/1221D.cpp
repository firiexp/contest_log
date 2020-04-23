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
    int q;
    cin >> q;
    while(q--){
        int n;
        scanf("%d", &n);
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld %lld", &a[i], &b[i]);
        }
        ll ans = 0;
        auto dp = make_v(3, n, INF<ll>);
        dp[0][0] = 0; dp[1][0] = b[0]; dp[2][0] = 2*b[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if(a[i-1]+j != a[i]+k){
                        dp[k][i] = min(dp[k][i], dp[j][i-1]+k*b[i]);
                    }
                }
            }
        }
        printf("%lld\n", min({dp[0].back(), dp[1].back(), dp[2].back()}));
    }
    return 0;
}