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

template <ll M = MOD> struct modint {
public:
    ll val;
    explicit modint(const ll x = 0) : val(x) {}
    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return modint(M-val); }
    modint inv(){
        ll u = 1, v = 0, s = 0, t = 1, m = M, x = val;
        while (x) {ll q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
        if(s < 0) s += M;
        return modint(s);
    }
    modint pow(ll n){
        ll u = 1, xx = val;
        while (n > 0){ if (n&1) u = u * xx % M; xx = xx * xx % M; n >>= 1; }
        return u;
    }
    modint &operator+=(const modint a){ val += a.val; if(val >= M) val -= M; return *this; }
    modint &operator-=(const modint a){ val += a.val; if(val < 0) val += M; return *this; }
    modint &operator*=(const modint a){ val = val * a.val % M; return *this; }
    modint &operator/=(const modint a){ val = (val*a.inv()) %M; return *this;}
};

using mint = modint<MOD>;

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    auto dp = make_v(n+1, 2, mint(0));
    dp[0][0] = mint(1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if(i < j) break;
            dp[i][j >= d] += dp[i-j][0];
            dp[i][1] += dp[i-j][1];
        }
    }
    cout << dp[n][1].val << "\n";
    return 0;
}