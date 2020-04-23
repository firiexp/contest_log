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
using ll = int64_t;
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
    Factorial<ll> f(10000, MOD);
    int k, n;
    cin >> k >> n;
    vector<int> cnt(2*k+1);
    vector<int> d(k+1, 1);
    for (int i = 0; i < k; ++i) {
        d[i+1] = d[i]*2%MOD;
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = i+1; j <= k; ++j) {
            cnt[i+j]++;
        }
    }
    for (int i = 2; i <= 2*k; ++i) {
        ll ans = 0;
        int p = cnt[i];
        for (int q = 0; q <= p; ++q) {
            if(i%2){
                (ans += (f.C(p, q)*d[q])%MOD*f.H(k-2*p+q, n-q)) %= MOD;
            }else {
                (ans += (f.C(p, q)*d[q])%MOD*f.H(k-2*p+q-1, n-q)) %= MOD;
                (ans += (f.C(p, q)*d[q])%MOD*f.H(k-2*p+q-1, n-q-1)) %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
