#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, size_t D> struct _Vec {
    using type = vector<typename _Vec<T, D-1>::type>;
};
template <class T> struct _Vec<T, 1> {
    using type = vector<T>;
};
template<class T, size_t D> using Vec = typename _Vec<T, D>::type;

template <class T>
vector<T> make_v(size_t size, const T& init){ return vector<T>(size, init); }

template<class... Ts>
auto make_v(size_t size, Ts... rest) {
    return vector<decltype(make_v(rest...))>(size, make_v(rest...));
}

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
    int m = n;
    string s;
    while(n){
        s = (n & 1 ? "1" : "0") + s;
        n >>= 1;
    }

    int t = static_cast<int>(s.length());
    Vec<ll, 3> dp = make_v(77, 2, 77, 0LL);
    Vec<ll, 3> dp2 = make_v(77, 2, 77, 0LL);
    dp[0][0][0] = 1;
    ll ans = 0;
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k <= t; ++k) {
                int lim = j ? 1 : s[i]- '0';
                for (int l = 0; l < lim+1; ++l) {
                    (dp[i+1][j || l < lim][k+l] += dp[i][j][k]) %= MOD;
                    (ans += dp[i][j][k]*l*pow_(2, t-i-1, MOD)*k) %= MOD;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;

}
