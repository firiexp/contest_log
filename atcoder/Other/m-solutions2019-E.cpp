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

static const long long MOD = 1000003;
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

template<typename T>
T mod_inv(T x, T M){
    T u = 1, t = 1, v = 0, s = 0, m = M;
    while (x) { T q = m/x; swap(s -= q*u, u); swap(t -= q*v, v); swap(m -= q*x, x); }
    if(s < 0) s += M;
    return s;
}

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
    int q;
    cin >> q;
    Factorial<ll> f(MOD-1, MOD);
    for (int i = 0; i < q; ++i) {
        ll x, d, n;
        scanf("%lli %lli %lli", &x, &d, &n);
        if(d == 0){
            printf("%lli\n", pow_(x, n, MOD));
        }else {
            ll y = x*mod_inv(d, MOD)%MOD;
            ll ans = pow_(d, n, MOD);
            if(n <= 10){
                for (int j = 0; j < n; ++j) {
                    ans = (ans*(y+j))%MOD;
                }
            }else {
                if(y+n-1 >= MOD){
                    ans = 0;
                }else {
                    ans = ans*f[y+n-1]%MOD;
                    if(y != 0) ans = ans*f[-(y-1)]%MOD;
                }
            }
            printf("%lli\n", ans);

        }
    }
    return 0;
}