#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    auto dp = make_v(n+1, 1<<(x+y+z), 0);
    int mask = (1<<(x+y+z))-1;
    dp[0][0] = 1;
    int a = (1<<(x-1))+(1<<(x+y-1))+(1<<(x+y+z-1));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1<<(x+y+z); ++j) {
            if(!dp[i][j]) continue;
            for (int k = 1; k <= 10; ++k) {
                int p = ((j << k)+ (1<<(k-1)))&mask;
                if((p & a) == a) (ans += (ll)pow_(10, n-i-1, MOD) * dp[i][j]) %= MOD;
                else (dp[i+1][p] += dp[i][j]) %= MOD;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
