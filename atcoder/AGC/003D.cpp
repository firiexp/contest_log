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

vector<int> get_prime(int n){
    if(n <= 1) return vector<int>();
    vector<bool> is_prime(n+1, true);
    vector<int> prime;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(is_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime){
            if(i*j > n) break;
            is_prime[i*j] = false;
            if(i % j == 0) break;
        }
    }
    return prime;
}


#include <random>
template< class T>
T pow_ (T x, uint64_t n, uint64_t M){
    T u = 1;
    if(n > 0){
        u = pow_(x, n/2, M);
        if (n % 2 == 0) u = (u*u) % M;
        else u = (((u * u)% M) * x) % M;
    }
    return u;
};

bool suspect(__uint128_t a, uint64_t s, uint64_t d, uint64_t n){
    __uint128_t x = pow_(a, d, n);
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
    for (auto &&p : v) {
        if(p >= n) break;
        if(!suspect(p, s, d, n)) return false;
    }
    return true;
}



const auto primes = get_prime(1000);
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
    }
}

map<ll, int> prime_factor(ll n, int d = 0){
    map<ll, int> a, res;
    if(!d) {
        for (auto &&i : primes) {
            while (n % i == 0){
                res[i]++;
                n /= i;
            }
        }
    }
    while(n != 1){
        if(miller_rabin(n)){
            a[n]++;
            break;
        }
        ll x = pollard_rho2(n);
        n /= x;
        a[x]++;
    }
    for (auto &&i : a) {
        if (miller_rabin(i.first)) {
            res[i.first] += i.second;
        } else {
            map<ll, int> b = prime_factor(i.first, d + 1);
            for (auto &&j : b) res[j.first] += j.second;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &&i : v) {
        scanf("%lld", &i);
    }
    map<map<ll, int>, int> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 1;
        for (ll j = 2; j <= 2100; ++j) {
            if(v[i] == j*j*j) ok = 0;
            while(v[i]%(j*j*j) == 0) v[i] /= j*j*j;
        }
        if(ok && v[i] != 1) {
            auto x = prime_factor(v[i]);
            for (auto &&j : x) {
                j.second %= 3;
            }
            m[x]++;
        }else ans++;
    }
    ans = ans > 0;
    for (auto &&i : m) {
        if(!i.second) continue;
        map<ll, int> y = i.first;
        for (auto &&k : y) {
            k.second = (3-k.second)%3;
        }
        if(m.count(y)){
            ans += max(m[y], i.second);
            m[y] = 0;
        }else {
            ans += i.second;
        }
    }
    cout << ans << "\n";
    return 0;
}