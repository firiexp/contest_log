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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;
#include <random>

using u128 = __uint128_t;

struct mod64 {
    u64 n;
    static u64 mod, inv, r2;
    mod64() : n(0) {}
    mod64(u64 x) : n(init(x)) {}
    static u64 init(u64 w) { return reduce(u128(w) * r2); }
    static void set_mod(u64 m) {
        mod = inv = m;
        for (int i = 0; i < 5; ++i) inv *= 2 - inv * m;
        r2 = -u128(m) % m;
    }
    static u64 reduce(u128 x) {
        u64 y = u64(x >> 64) - u64((u128(u64(x) * inv) * mod) >> 64);
        return ll(y) < 0 ? y + mod : y;
    };
    mod64& operator+=(mod64 x) { n += x.n - mod; if(ll(n) < 0) n += mod; return *this; }
    mod64 operator+(mod64 x) const { return mod64(*this) += x; }
    mod64& operator*=(mod64 x) { n = reduce(u128(n) * x.n);  return *this; }
    mod64 operator*(mod64 x) const { return mod64(*this) *= x; }
    u64 val() const { return reduce(n); }
};

u64 mod64::mod, mod64::inv, mod64::r2;


bool suspect(u64 a, u64 s, u64 d, u64 n){
    mod64::set_mod(n);
    mod64 x(1), xx(a), one(x), minusone(n-1);
    while(d > 0){
        if(d&1) x = x * xx;
        xx = xx * xx;
        d >>= 1;
    }
    if (x.n == one.n) return true;
    for (int r = 0; r < s; ++r) {
        if(x.n == minusone.n) return true;
        x = x * x;
    }
    return false;
}

template<class T>
bool miller_rabin(T n){
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    u64 d = n - 1, s = 0;
    while (!(d&1)) {++s; d >>= 1;}
    static const u64 v[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    static const u64 v_small[] = {2, 7, 61};
    if(n <= 4759123141LL){
        for (auto &&p : v_small) {
            if(p >= n) break;
            if(!suspect(p, s, d, n)) return false;
        }
    }else {
        for (auto &&p : v) {
            if(p >= n) break;
            if(!suspect(p, s, d, n)) return false;
        }
    }
    return true;
}

template<typename T>
struct ExactDiv {
    T t, i, val;
    ExactDiv() {}
    ExactDiv(T n) : t(T(-1) / n), i(mul_inv(n)) , val(n) {};
    T mul_inv(T n) {
        T x = n;
        for (int i = 0; i < 5; ++i) x *= 2 - n * x;
        return x;
    }
    bool divide(T n) const {
        if(val == 2) return !(n & 1);
        return n * this->i <= this->t;
    }
};

vector<ExactDiv<u64>> get_prime(int n){
    if(n <= 1) return vector<ExactDiv<u64>>();
    vector<bool> is_prime(n+1, true);
    vector<ExactDiv<u64>> prime;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j.val > n) break;
            is_prime[i*j.val] = false;
            if(j.divide(i)) break;
        }
    }
    return prime;
}
const auto primes = get_prime(1000);

random_device rng;


template<class T>
T pollard_rho2(T n) {
    uniform_int_distribution<T> ra(1, n-1);
    mod64::set_mod(n);
    while(true){
        u64 c_ = ra(rng), g = 1, r = 1, m = 500;
        while(c_ == n-2) c_ = ra(rng);
        mod64 y(ra(rng)), xx(0), c(c_), ys(0), q(1);
        while(g == 1){
            xx.n = y.n;
            for (int i = 1; i <= r; ++i) {
                y *= y; y += c;
            }
            T k = 0; g = 1;
            while(k < r && g == 1){
                for (int i = 1; i <= (m > (r-k) ? (r-k) : m); ++i) {
                    ys.n = y.n;
                    y *= y; y += c;
                    u64 xxx = xx.val(), yyy = y.val();
                    q *= mod64(xxx > yyy ? xxx - yyy : yyy - xxx);
                }
                g = __gcd<ll>(q.val(), n);
                k += m;
            }
            r *= 2;
        }
        if(g == n) g = 1;
        while (g == 1){
            ys *= ys; ys += c;
            u64 xxx = xx.val(), yyy = ys.val();
            g = __gcd<ll>(xxx > yyy ? xxx - yyy : yyy - xxx, n);
        }
        if (g != n && miller_rabin(g)) return g;
    }
}

template<class T>
vector<T> prime_factor(T n, int d = 0){
    vector<T> a, res;
    if(!d) for (auto &&i : primes) {
            while (i.divide(n)){
                res.emplace_back(i.val);
                n /= i.val;
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
    sort(res.begin(),res.end());
    return res;
}

int main() {
    int q;
    cin >> q;
    auto f = [&](ll x){
        if(x == 2) return false;
        if(x%2 == 0) return true;
        for (ll p = 2; p+2 <= x; p *= 2) {
            if(miller_rabin(x-p)) return true;
            ll ok = 0, ng = 1000000001; // p^2
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if(mid*mid <= x-p) ok = mid;
                else ng = mid;
            }
            if(ok*ok == x-p && miller_rabin(ok)) return true;
            ok = 0, ng = 1000001;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if(mid*mid*mid <= x-p) ok = mid;
                else ng = mid;
            }
            if(ok*ok*ok == x-p && miller_rabin(ok)) return true;
            ok = 0, ng = 32001;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if(mid*mid*mid*mid <= x-p) ok = mid;
                else ng = mid;
            }
            if(ok*ok*ok*ok == x-p && miller_rabin(ok)) return true;
            ok = 0, ng = 4001;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if(mid*mid*mid*mid*mid <= x-p) ok = mid;
                else ng = mid;
            }
            if(ok*ok*ok*ok*ok == x-p && miller_rabin(ok)) return true;
            for (auto &&i : primes) {
                u64 pp = i.val*i.val*i.val*i.val*i.val;
                for (int j = 6; j*log10(i.val) < 18.5; ++j) {
                    pp *= i.val;
                    if(pp == x-p) return true;
                }
            }
        }
        return false;
    };
    while(q--){
        ll x;
        cin >> x;
        puts(f(x) ? "Yes" : "No");
    }
    return 0;
}