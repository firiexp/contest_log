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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

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
        return static_cast<T>(facts[k]);
    }

    T operator[](const int &k) const {
        return static_cast<T>(facts[k]);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>(facts[p]*  factinv[q] % mod * factinv[p-q] % mod);
    }

    T P(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return static_cast<T>(facts[p] * factinv[q-p] % mod);
    }

    T H(int p, int q) const {
        if(p < 0 || q < 0) return 0;
        return static_cast<T>(q == 0 ? 1 : C(p+q-1, q));
    }
};

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

int main() {
    ll n, k;
    ll r = 0;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        int q = 0;
        while (a > 0) {
            a /= 2;
            q++;
        }
        v.emplace_back(q);
        r += q + 1;
    }
    if(k == 0){
        cout << 1 << "\n";
        return 0;
    }
    k = min(k,r);
    sort(v.begin(), v.end());
    Vec<ll, 3> dp = make_v(51, 3501, 2, 0LL);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 65*i; ++j) {
            for (int l = 0; l < v[i-1]; ++l) {
                if(j-l >= 0){
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j-l][0])%MOD;
                    dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-l][1])%MOD;
                }
            }
            if(j-v[i-1] >= 0){
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-v[i-1]][0] + dp[i-1][j-v[i-1]][1]) % MOD;
            }
        }
    }
    ll ans = dp[n][k][0];
    for (int i = 0; i <= k; ++i) {
        ans = (ans + dp[n][i][1]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
