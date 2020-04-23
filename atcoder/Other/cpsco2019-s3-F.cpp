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

template <class T> class Factorial {
    T mod;
    vector<uint64_t> facts, factinv;

public:
    Factorial(int n, T mod) : facts(static_cast<u32>(n+1)), factinv(static_cast<u32>(n+1)), mod(mod) {
        facts[0] = 1;
        for (int i = 1; i < n+1; ++i) facts[i] = facts[i-1]*i % mod;
        factinv[n] = pow_(facts[n], static_cast<uint64_t>(mod - 2), static_cast<uint64_t>(mod));
        for (int i = n-1; i >= 0; --i) factinv[i] = factinv[i+1] * (i+1) % mod;
    }

    T fact(int k) const {
        if(k >= 0) return static_cast<T>(facts[k]);
        else return static_cast<T>(factinv[-k]);
    }

    T operator[](const int &k) const {
        if(k >= 0) return static_cast<T>(facts[k]);
        else return static_cast<T>(factinv[-k]);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>(facts[p]*  factinv[q] % mod * factinv[p-q] % mod);
    }

    T P(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>((facts[p] * factinv[p-q]) % mod);
    }

    T H(int p, int q) const {
        if(p < 0 || q < 0) return 0;
        return static_cast<T>(q == 0 ? 1 : C(p+q-1, q));
    }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    auto dp = make_v(a+b+1, a+b+1, 0LL);
    for (int i = 0; i <= a+b; ++i) {
        for (int j = 0; j <= a+b; ++j) {
            if(j == 0) dp[i][j] = 1;
            else if(j > i) dp[i][j] = 0;
            else {
                (dp[i][j] += dp[i-1][j-1]*(i-j)+(j+1)*dp[i-1][j]) %= MOD;
            }
        }
    }
    Factorial<ll> f(n, MOD);
    ll ans = 0, ans2 = f.C(n, n-a-b);

    cout << ans*ans2%MOD << "\n";
    return 0;
}