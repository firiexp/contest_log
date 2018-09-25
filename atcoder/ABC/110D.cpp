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

#include <random>
template< class T>
T pow_2 (T x, uint64_t n, uint64_t M){
    T u = 1;
    if(n > 0){
        u = pow_2(x, n/2, M);
        if (n % 2 == 0) u = (u*u) % M;
        else u = (((u * u)% M) * x) % M;
    }
    return u;
};

bool suspect(__uint128_t a, uint64_t s, uint64_t d, uint64_t n){
    __uint128_t x = pow_2(a, d, n);
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
        if(x == n-1) return true;
        x = x * x % n;
    }
    return false;
}

template<class T>
bool miller_rabin(T m){
    uint64_t n = m;
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    uint64_t d = n - 1, s = 0;
    while (!(d&1)) {++s; d >>= 1;}
    vector<uint64_t> v = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if(n <= 4759123141LL) v = {2, 7, 61};
    if(n <= 366018361) v = {1143370, 2350307676};
    for (auto &&p : v) {
        if(p >= n) break;
        if(!suspect(p, s, d, n)) return false;
    }
    return true;
}

vector<int> get_prime(int n) {
    if(n <= 1) return vector<int>{};
    vector<bool> prime(static_cast<unsigned int>(n + 1), true);
    vector<int> res;
    prime[0] = false; prime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(prime[i]) for(int j = i << 1; j <= n; j += i) prime[j] = false;
    }
    for (int i = 2; i <= n; ++i) {
        if(prime[i]) res.emplace_back(i);
    }
    return res;
}
const auto p = get_prime(100000);
random_device rng;
template<class T>
T pollard_rho2(T n) {
    uniform_int_distribution<T> ra(1, n-1);
    while(true){
        T c = ra(rng), g = 1, r = 1, y = ra(rng),m = 1900,
                ys = 0, q = 1, xx = 0;
        while(c == n-2) c = ra(rng);
        while(g == 1){
            xx = y;
            for (int i = 1; i <= r; ++i) {
                y = static_cast<T>(((__uint128_t)y * y) % n);
                y = static_cast<T>((__uint128_t)y + c) % n;
            }
            T k = 0; g = 1;
            while(k < r && g == 1){
                for (int i = 1; i <= (m > (r-k) ? (r-k) : m); ++i) {
                    ys = y;
                    y = static_cast<T>(((__uint128_t)y * y) % n);
                    y = static_cast<T>((__uint128_t)y + c) % n;
                    q = static_cast<T>(((__uint128_t)q * (xx > y ? xx - y : y - xx)) % n);
                }
                g = __gcd(q, n);
                k += m;
            }
            r *= 2;
        }
        if(g == n) g = 1;
        while (g == 1){
            ys = static_cast<T>(((__uint128_t)ys * ys) % n);
            ys = static_cast<T>((__uint128_t)ys + c) % n;
            g = __gcd(xx > ys ? xx - ys : ys - xx, n);
        }
        if (g != n && miller_rabin(g)) return g;
        break;
    }
}

template<class T>
vector<T> prime_factor(T n, int d = 0){
    vector<T> a, res;
    if(!d) for (auto &&i : p) {
            while (n % i == 0){
                res.emplace_back(i);
                n /= i;
            }
        }
    while(n != 1){
        if(miller_rabin(n)){
            a.emplace_back(n);
            break;
        }
        T x = pollard_rho2(n);
        n /= x;
        a.emplace_back(x);
    }
    for (auto &&i : a) {
        if (miller_rabin(i)) {
            res.emplace_back(i);
        } else {
            vector<T> b = prime_factor(i, d + 1);
            for (auto &&j : b) res.emplace_back(j);
        }
    }
    return res;
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

int main() {
    int n, m;
    cin >> n >> m;
    auto v = prime_factor(m);
    map<int, int> ma;
    for (auto &&x : v) {
        ma[x]++;
    }
    Factorial<ll> f(250000, MOD);
    ll ans = 1;
    for (auto &&x : ma) {
        ans = (ans * f.C(n+x.second-1, x.second))%MOD;
    }
    cout << ans << "\n";
    return 0;
}
