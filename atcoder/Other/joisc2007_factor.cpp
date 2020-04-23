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
const auto p = get_prime(10000);
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
map<T, int> prime_factor(T n, int d = 0){
    vector<T> a;
    map<T, int> res;
    if(!d) for (auto &&i : p) {
            while (n % i == 0){
                res[i]++;
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
            res[i]++;
        } else {
            map<T, int> b = prime_factor(i, d + 1);
            for (auto &&j : b) res[j.first] += j.second;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    map<int, int> v = prime_factor(n);
    int ans = 0;
    for (auto &&i : v) {
        for (int j = i.first, k = 0; k < i.second; j += i.first) {
            ans = max(ans, j);
            int x = j;
            while(x%i.first == 0){
                x /= i.first;
                k++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
