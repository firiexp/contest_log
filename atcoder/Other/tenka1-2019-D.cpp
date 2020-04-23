#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 998244353;
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
    int sum = accumulate(v.begin(), v.end() , 0);
    auto dp = make_v(n+1, sum+1, 0LL);
    dp[0][0] = 1;
    auto dp2 = dp;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            (dp[i+1][j+v[i]] += dp[i][j]) %= MOD;
            (dp[i+1][j] += dp[i][j]*2) %= MOD;
            (dp2[i+1][j+v[i]] += dp2[i][j]) %= MOD;
            (dp2[i+1][j] += dp2[i][j]) %= MOD;
        }
        x += v[i];
    }
    ll ans = pow_(3, n-1, MOD);
    for (int i = (sum+1)/2; i <= sum; ++i) {
        (ans += MOD - dp[n][i]) %= MOD;
    }
    if(sum%2 == 0){
        (ans += dp2[n][sum/2]) %= MOD;
    }
    cout << (ans*3)%MOD << "\n";
    return 0;
}
